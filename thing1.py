import os
import sys
import math
import torch
import torch.nn as nn
import torch.nn.functional as F

CKPT_PATH = "golomb_net.pt"
K_CANDIDATES = 16
STATE_DIM = 48
HIDDEN_DIM = 56

EXACT_RULERS = {
    3: [0, 1, 3],
    4: [0, 1, 4, 6],
    5: [0, 1, 4, 9, 11],
    6: [0, 1, 4, 10, 12, 17],
    7: [0, 1, 4, 10, 18, 23, 25],
    8: [0, 1, 4, 9, 15, 22, 32, 34],
    9: [0, 1, 5, 12, 25, 27, 35, 41, 44],
    10: [0, 1, 6, 10, 23, 26, 34, 41, 53, 55],
}


# =====================================================================
# 1. MODEL DEFINITION & CHECKPOINT LOADER
# =====================================================================

class ResBlock(nn.Module):
    def __init__(self, dim: int):
        super().__init__()
        self.fc1 = nn.Linear(dim, dim)
        self.ln1 = nn.LayerNorm(dim)
        self.fc2 = nn.Linear(dim, dim)
        self.ln2 = nn.LayerNorm(dim)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        h = F.silu(self.ln1(self.fc1(x)))
        h = self.ln2(self.fc2(h))
        return F.silu(x + h)


class GolombNet(nn.Module):
    def __init__(self, state_dim: int = STATE_DIM, hidden_dim: int = HIDDEN_DIM, k_cand: int = K_CANDIDATES):
        super().__init__()
        self.input_layer = nn.Sequential(
            nn.Linear(state_dim, hidden_dim),
            nn.LayerNorm(hidden_dim),
            nn.SiLU(),
        )
        self.res1 = ResBlock(hidden_dim)
        self.res2 = ResBlock(hidden_dim)
        self.policy_head = nn.Linear(hidden_dim, k_cand)
        self.value_head = nn.Linear(hidden_dim, 1)

    def forward(self, x: torch.Tensor):
        h = self.input_layer(x)
        h = self.res1(h)
        h = self.res2(h)
        return self.policy_head(h), self.value_head(h).squeeze(-1)


def load_model(ckpt_path: str, device: torch.device) -> GolombNet:
    model = GolombNet().to(device)
    if os.path.exists(ckpt_path):
        state = torch.load(ckpt_path, map_location=device, weights_only=True)
        model.load_state_dict({k: v.float() for k, v in state.items()})
    model.eval()
    return model


# =====================================================================
# 2. GPU ENVIRONMENT HELPERS
# =====================================================================

@torch.no_grad()
def get_k_valid_deltas_gpu(
    marks: torch.Tensor,
    used: torch.Tensor,
    t: int,
    k_cand: int = K_CANDIDATES,
    chunk_size: int = 256,
) -> torch.Tensor:
    B = marks.shape[0]
    max_diff = used.shape[1]
    device = marks.device
    last_mark = marks[:, t - 1 : t]
    placed = marks[:, :t].unsqueeze(1)

    offset = 1
    collected = []
    total_found = torch.zeros(B, dtype=torch.int64, device=device)

    while True:
        cand_deltas = torch.arange(offset, offset + chunk_size, device=device).unsqueeze(0)
        cand_pos = last_mark + cand_deltas
        diffs = (cand_pos.unsqueeze(2) - placed).clamp(min=0, max=max_diff - 1)

        in_bounds = cand_pos < max_diff
        collisions = used.gather(1, diffs.reshape(B, -1)).view(B, chunk_size, t).any(dim=2)
        valid_mask = (~collisions) & in_bounds

        collected.append((cand_deltas.expand(B, -1), valid_mask))
        total_found += valid_mask.sum(dim=1)

        if (total_found >= k_cand).all() or offset + chunk_size >= max_diff:
            break
        offset += chunk_size

    all_deltas = torch.cat([c[0] for c in collected], dim=1)
    all_valid = torch.cat([c[1] for c in collected], dim=1)
    total_W = all_deltas.shape[1]

    priority = all_valid.to(torch.int64) * (total_W + 1 - torch.arange(total_W, device=device).unsqueeze(0))
    _, topk_idx = torch.topk(priority, k=k_cand, dim=1, largest=True, sorted=True)
    return all_deltas.gather(1, topk_idx)


@torch.no_grad()
def extract_state_features_gpu(
    marks: torch.Tensor,
    used: torch.Tensor,
    valid_deltas: torch.Tensor,
    t: int,
    n: int,
) -> torch.Tensor:
    B = marks.shape[0]
    device = marks.device
    cur_len = marks[:, t - 1].float()
    norm_scale = float(max(n * n, 10))

    f_global = torch.stack([
        torch.full((B,), t / n, device=device),
        torch.full((B,), (n - t) / n, device=device),
        torch.full((B,), n / 150.0, device=device),
        cur_len / norm_scale,
        (t * (t - 1) / 2.0) / (cur_len + 1.0),
        valid_deltas[:, 0].float() / max(n, 1),
    ], dim=1)

    f_cand = (valid_deltas.float() - valid_deltas[:, 0:1].float()) / max(n, 5.0)

    bin_w = max(1, n // 2)
    span = 16 * bin_w
    used_slice = used[:, 1 : 1 + span].float()
    if used_slice.shape[1] < span:
        used_slice = F.pad(used_slice, (0, span - used_slice.shape[1]))
    f_spec = used_slice.view(B, 16, bin_w).mean(dim=2)

    f_gaps = torch.zeros((B, 10), dtype=torch.float32, device=device)
    if t > 1:
        num_g = min(10, t - 1)
        recent_gaps = (marks[:, t - num_g : t] - marks[:, t - num_g - 1 : t - 1]).float() / max(n, 1)
        f_gaps[:, 10 - num_g :] = recent_gaps

    return torch.cat([f_global, f_cand, f_spec, f_gaps], dim=1)


# =====================================================================
# 3. NEURAL-GUIDED SEARCH & ALGEBRAIC HYBRID SOLVER
# =====================================================================

@torch.no_grad()
def neural_guided_search(
    model: GolombNet,
    n: int,
    device: torch.device,
    batch_size: int = 512,
    prefix: list[int] | None = None,
) -> list[int]:
    """
    Runs a massive parallel GPU batch of neural-guided rollouts from `prefix`
    (or from [0] if prefix is None) and returns the shortest ruler found.
    """
    start_t = len(prefix) if prefix else 1
    base_span = prefix[-1] if prefix else 0
    max_diff = max(4096, base_span + n * n * 3)

    marks = torch.zeros((batch_size, n), dtype=torch.int64, device=device)
    used = torch.zeros((batch_size, max_diff), dtype=torch.bool, device=device)

    if prefix:
        pref_t = torch.tensor(prefix, dtype=torch.int64, device=device)
        marks[:, :start_t] = pref_t.unsqueeze(0)
        diffs = []
        for i in range(start_t):
            for j in range(i + 1, start_t):
                diffs.append(prefix[j] - prefix[i])
        if diffs:
            d_tensor = torch.tensor(diffs, dtype=torch.int64, device=device).unsqueeze(0).expand(batch_size, -1)
            used.scatter_(1, d_tensor, True)

    # Multi-temperature schedule across batch slots for diverse exploration
    temps = torch.linspace(0.3, 1.4, batch_size, device=device).unsqueeze(1)

    for t in range(start_t, n):
        valid_deltas = get_k_valid_deltas_gpu(marks, used, t, K_CANDIDATES)
        state_feat = extract_state_features_gpu(marks, used, valid_deltas, t, n)

        logits, _ = model(state_feat)
        probs = F.softmax(logits / temps, dim=-1)
        actions = torch.multinomial(probs, num_samples=1).squeeze(-1)

        # Slot 0: pure greedy fallback; Slot 1: neural policy argmax
        actions[0] = 0
        if batch_size > 1:
            actions[1] = logits[1].argmax(dim=-1)

        chosen_delta = valid_deltas.gather(1, actions.unsqueeze(1))
        new_pos = marks[:, t - 1 : t] + chosen_delta
        new_diffs = (new_pos - marks[:, :t]).clamp(min=0, max=max_diff - 1)

        used.scatter_(1, new_diffs, True)
        marks[:, t] = new_pos.squeeze(1)

    _, best_idx = torch.min(marks[:, -1], dim=0)
    return marks[best_idx].cpu().tolist()


def is_prime(num: int) -> bool:
    if num < 2:
        return False
    for d in range(2, int(math.isqrt(num)) + 1):
        if num % d == 0:
            return False
    return True


def primitive_roots(p: int, limit: int = 3) -> list[int]:
    phi = p - 1
    factors = []
    temp, d = phi, 2
    while d * d <= temp:
        if temp % d == 0:
            factors.append(d)
            while temp % d == 0:
                temp //= d
        d += 1
    if temp > 1:
        factors.append(temp)

    roots = []
    for g in range(2, p):
        if all(pow(g, phi // f, p) != 1 for f in factors):
            roots.append(g)
            if len(roots) >= limit:
                break
    return roots


def generate_ruzsa_seed(n: int) -> list[int]:
    best_ruler = None
    best_span = 10**9
    for p in range(n + 1, n + 65):
        if not is_prime(p):
            continue
        M = p * (p - 1)
        roots = primitive_roots(p, limit=3)
        multipliers = [1]
        for m in range(2, min(M, 75)):
            if math.gcd(m, M) == 1:
                multipliers.append(m)
                if len(multipliers) >= 16:
                    break

        for g in roots:
            base_pts = []
            cur = g
            for x in range(1, p):
                base_pts.append((x * p - cur * (p - 1)) % M)
                cur = (cur * g) % p

            for m in multipliers:
                pts = sorted((val * m) % M for val in base_pts)
                circle = pts + [v + M for v in pts]
                for i in range(len(pts)):
                    span = circle[i + n - 1] - circle[i]
                    if span < best_span:
                        best_span = span
                        offset = circle[i]
                        best_ruler = [circle[i + k] - offset for k in range(n)]
    return best_ruler


def solve(n: int, ckpt_path: str = CKPT_PATH) -> list[int]:
    if n in EXACT_RULERS:
        return EXACT_RULERS[n]

    device = "cpu"
    model = load_model(ckpt_path, device)

    candidates = []

    # 1. Full Neural-Guided GPU Rollout Search for N <= 45
    if n <= 45:
        b_size = 512 if n <= 28 else 256
        candidates.append(neural_guided_search(model, n, device, batch_size=b_size))

    # 2. Algebraic Seed + Neural Tail Re-Packing for N >= 20
    if n >= 20:
        ruzsa_seed = generate_ruzsa_seed(n)
        candidates.append(ruzsa_seed)

        # Strip the last `strip_k` marks and let GolombNet re-pack the tail
        for strip_k in (2, 4):
            if n - strip_k >= 10:
                prefix = ruzsa_seed[:-strip_k]
                repacked = neural_guided_search(
                    model, n, device, batch_size=128, prefix=prefix
                )
                candidates.append(repacked)
                # Also try reversing the ruler and re-packing the opposite end
                rev_seed = [ruzsa_seed[-1] - x for x in reversed(ruzsa_seed)]
                rev_repacked = neural_guided_search(
                    model, n, device, batch_size=128, prefix=rev_seed[:-strip_k]
                )
                candidates.append(rev_repacked)

    best_ruler = min(candidates, key=lambda r: r[-1])
    return best_ruler
import os
import torch

# 1. Set PyTorch internal thread counts to 1
torch.set_num_threads(1)
torch.set_num_interop_threads(1)

# 2. Set environment variables for underlying BLAS libraries
os.environ["OMP_NUM_THREADS"] = "1"
os.environ["MKL_NUM_THREADS"] = "1"
os.environ["OPENBLAS_NUM_THREADS"] = "1"
os.environ["VECLIB_MAXIMUM_THREADS"] = "1"
os.environ["NUMEXPR_NUM_THREADS"] = "1"
import time
if __name__ == "__main__":
    for test_n in range(3, 151):
        now = time.time()
        res = solve(test_n)
        print(f"N = {test_n:3d} | Length = {res[-1]:6d} | Marks: {res}... | Time: {time.time() - now}")