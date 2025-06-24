from string import ascii_letters
import sys

input = sys.stdin.readline

s_len, t_len = map(int, input().split())
src_str = input().rstrip()
dst_str = input().rstrip()

pos_map = {c: [] for c in ascii_letters}
for i, ch in enumerate(src_str):
    pos_map[ch].append(i)

INF = 10**15
prev_arr = [INF]*s_len

for p in pos_map.get(dst_str[0], []):
    prev_arr[p] = 0

for i in range(1, t_len):

    best_arr = [INF]*s_len
    tmp = INF
    for j in range(s_len):
        tmp = min(tmp+1, prev_arr[j])
        best_arr[j] = tmp
    tmp = INF
    for j in range(s_len-1, -1, -1):
        tmp = min(tmp+1, prev_arr[j])
        best_arr[j] = min(best_arr[j], tmp)

    cur = [INF]*s_len
    pre = dst_str[i-1]
    curc  = dst_str[i]
    for prev_pos in pos_map.get(pre, []):
        cost_base = best_arr[prev_pos] + 1
        if cost_base >= INF:
            continue

        for next_pos in (prev_pos-1, prev_pos+1):
            if 0 <= next_pos < s_len and src_str[next_pos] == curc:
                if cost_base < cur[next_pos]:
                    cur[next_pos] = cost_base

    prev_arr = cur

ans = min(prev_arr)
print(ans if ans < INF else -1)