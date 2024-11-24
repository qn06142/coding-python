from typing import List

N = 31
K = 51
INF = 1e18

dp = [[[-1 for _ in range(K)] for _ in range(N)] for _ in range(N)]

def DP(w, h, cnt):
    if dp[w][h][cnt] != -1:
        return dp[w][h][cnt]
    if w * h < cnt:
        return INF
    if cnt == 0 or w * h == cnt:
        return 0

    res = INF
    for c1 in range(cnt + 1):
        for i in range(1, w):
            res = min(res, DP(i, h, c1) + DP(w - i, h, cnt - c1) + h * h)
        for j in range(1, h):
            res = min(res, DP(w, j, c1) + DP(w, h - j, cnt - c1) + w * w)
    dp[w][h][cnt] = res
    return res

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    print(DP(n, m, k))