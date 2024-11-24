n = int(input())

a = tuple(int(i) for i in input().split())
pref = [a[0]]
for i in a[1:]:
    pref.append(pref[-1] + i)
dp1 = [[0 for i in range(0, n + 1)] for _ in range(0, n + 1)]
dp2 = [[0 for i in range(0, n + 1)] for _ in range(0, n + 1)]

for i in range(1, n + 1):
    for j in range(i, n + 1):
        dp1[i][j] = dp[i - 1][j - 1]