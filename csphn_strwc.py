import sys
from collections import deque

def solve_one(N, L, S):
    # available_blocks[pos] = số block liên tiếp có thể bắt đầu ở pos (theo vị trí mod L)
    available_blocks = [0] * N

    # Xử lý từng residue r = 0..L-1
    for r in range(L):
        # tạo dãy ký tự cho residue r: positions r + t*L
        seq = []
        positions = []
        t = 0
        pos = r
        while pos < N:
            seq.append(S[pos])
            positions.append(pos)
            pos += L
            t += 1
        m = len(seq)
        if m == 0:
            continue

        # two-pointer: với mỗi l, tìm rptr lớn nhất sao cho trong [l..rptr] không có >1 chữ cái cố định khác nhau
        # ta dùng count cho 26 chữ cái và biến distinct
        counts = [0]*26
        distinct = 0
        l = 0
        rptr = 0
        # rptr là chỉ số đầu tiên không hợp lệ (ngoại biên), ta sẽ set segment_end[l] = rptr-1
        segment_end = [0]*m
        while l < m:
            # mở rộng rptr đến khi hợp lệ
            while rptr < m:
                ch = seq[rptr]
                if ch == '*':
                    rptr += 1
                    continue
                idx = ord(ch) - ord('a')
                if counts[idx] == 0 and distinct == 1:
                    # nếu thêm sẽ làm distinct > 1 => không được
                    break
                if counts[idx] == 0:
                    distinct += 1
                counts[idx] += 1
                rptr += 1
            # [l .. rptr-1] là hợp lệ maximal cho l hiện tại
            segment_end[l] = rptr - 1
            # move l lên 1 (thu hẹp), cập nhật counts/distinct
            chl = seq[l]
            if chl != '*':
                idxl = ord(chl) - ord('a')
                counts[idxl] -= 1
                if counts[idxl] == 0:
                    distinct -= 1
            l += 1
            # nếu l > rptr then đồng bộ rptr = l
            if rptr < l:
                rptr = l

        # gán available_blocks cho các vị trí gốc
        for t_idx, pos in enumerate(positions):
            available_blocks[pos] = 1 + (segment_end[t_idx] - t_idx)

    # Ta chỉ quan tâm các start i có i + L -1 <= N-1  => i in [0, N-L]
    if N < L:
        return 0

    # sliding window minimum trên available_blocks với cửa sổ độ L
    dq = deque()  # store indices, increasing by value
    max_len = 0
    arr = available_blocks
    for i in range(N):
        # push i
        while dq and arr[dq[-1]] >= arr[i]:
            dq.pop()
        dq.append(i)
        # pop out-of-window indices
        if i >= L:
            if dq and dq[0] == i - L:
                dq.popleft()
        # when we've filled first window ending at i (i >= L-1)
        if i >= L - 1:
            start = i - (L - 1)
            min_blocks = arr[dq[0]]
            # min_blocks có thể là 0 (nếu không có block), nhưng start..start+L-1 tồn tại
            candidate = min_blocks * L
            if candidate > max_len:
                max_len = candidate

    return max_len

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        N = int(next(it)); L = int(next(it))
        S = next(it).strip()
        res = solve_one(N, L, S)
        out_lines.append(str(res))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()
