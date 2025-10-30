#!/usr/bin/env python3
# make_payload.py  (stdlib + ortools)
# Produces icpccentralh.ascii.txt (base64 of lzma(compressed varint stream))
# Format version = 2 (delta-encoded sorted ranks per task)

from ortools.sat.python import cp_model
import lzma, base64, sys

# ---------- solver wrapper (same as before) ----------
def solve_triangle_return_solutions(n, T, max_time_seconds=30):
    if n % 3 != 0:
        return []
    k = n // 3 + 1
    model = cp_model.CpModel()
    positions = [model.NewIntVar(1, n, f'p{i}') for i in range(n)]
    model.AddAllDifferent(positions)
    side1 = positions[0:k]
    side2 = positions[k-1:2*k-1]
    side3 = positions[2*k-2:] + [positions[0]]
    model.Add(sum(side1) == T)
    model.Add(sum(side2) == T)
    model.Add(sum(side3) == T)
    solver = cp_model.CpSolver()
    solver.parameters.max_time_in_seconds = max_time_seconds
    solver.parameters.enumerate_all_solutions = True
    solutions = []
    class Collector(cp_model.CpSolverSolutionCallback):
        def __init__(self, vars_):
            cp_model.CpSolverSolutionCallback.__init__(self)
            self.vars = vars_
        def on_solution_callback(self):
            solutions.append([self.Value(v) for v in self.vars])
    collector = Collector(positions)
    solver.Solve(model, collector)
    return solutions

# ---------- Lehmer rank/unrank ----------
def perm_to_rank(perm):
    n = len(perm)
    rem = list(range(1, n+1))
    rank = 0
    for i in range(n):
        idx = rem.index(perm[i])
        rank = rank * (n - i) + idx
        rem.pop(idx)
    return rank

def rank_to_perm(rank, n):
    digits = [0] * n
    r = rank
    for i in range(1, n+1):
        digits[n - i] = r % i
        r //= i
    rem = list(range(1, n+1))
    perm = []
    for d in digits:
        perm.append(rem.pop(d))
    return perm

# ---------- unsigned LEB128 varint ----------
def encode_varint(x):
    out = bytearray()
    while True:
        to_write = x & 0x7F
        x >>= 7
        if x:
            out.append(to_write | 0x80)
        else:
            out.append(to_write)
            break
    return bytes(out)

# ---------- pack with delta encoding per task ----------
def build_payload(tasks_results, lzma_preset=9):
    """
    tasks_results: list of (n,T, [solutions]) where solutions is list of permutations
    Format (varints):
      format_version (=2)
      num_tasks
      for each task:
        n
        T
        num_solutions
        if num_solutions == 0: nothing else
        else:
          first_rank
          delta1, delta2, ... (num_solutions-1 deltas)  (each as varint)
    """
    b = bytearray()
    # version
    b += encode_varint(2)  # format version 2 = delta-encoded ranks
    b += encode_varint(len(tasks_results))
    for n, T, solutions in tasks_results:
        b += encode_varint(n)
        b += encode_varint(T)
        b += encode_varint(len(solutions))
        if solutions:
            ranks = [perm_to_rank(sol) for sol in solutions]
            ranks.sort()
            prev = ranks[0]
            b += encode_varint(prev)
            for r in ranks[1:]:
                delta = r - prev
                b += encode_varint(delta)
                prev = r
    compressed = lzma.compress(bytes(b), preset=(lzma_preset | lzma.PRESET_EXTREME))
    return base64.b64encode(compressed).decode('ascii')

# ---------- build tasks and write file ----------
if __name__ == "__main__":
    # adjust args_list as you want (copied from your script)
    args_list = [(n, T) for n in range(3, 12) for T in range(1, 30)] #+ [(n, T) for n in range(12, 13) for T in range(1, 41)]
    tasks_results = []
    print("Solving tasks... (this may take time)")
    for n, T in args_list:
        sols = solve_triangle_return_solutions(n, T)
        tasks_results.append((n, T, sols))
        # progress print
        print("done", n, T, "solutions:", len(sols))
    payload = build_payload(tasks_results, lzma_preset=9)
    with open("icpccentralh.ascii.txt", "w", encoding="ascii") as f:
        f.write(payload)
    print("Wrote icpccentralh.ascii.txt, length:", len(payload))
