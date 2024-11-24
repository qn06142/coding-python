k, n = [int(i) for i in input().split()]
k += 8
a = [int(i) for i in input().split()]
a.sort(reverse=True)
a = [0] + a
dp = [[float('inf') for i in range(k + 1)] for j in range(n + 1)]
for i in range(1, n + 1):
    dp[i][0] = 0
for i in range(1, n + 1):
    for j in range(1, min(i // 3 + 1, k + 1)):
        dp[i][j] = min(dp[i - 2][j - 1] + (a[i - 1] - a[i]) ** 2, dp[i - 1][j])
        # print(dp[i - 2][j - 1] + (a[i - 1] - a[i]) ** 2, dp[i - 1][j], ":", i, j, "(", a[i - 1], a[i], ")")

print(dp[n][k])
