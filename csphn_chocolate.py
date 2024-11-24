MAX_N = 1005
dp = [[0] * (MAX_N + 1) for _ in range(MAX_N + 1)]

n = int(input())
for i in range(n + 1):
    dp[i][0] = 0
    dp[i][i] = 1

for i in range(1, n + 1):
    for k in range(i):
        dp[i][k] = dp[i - 1][k - 1] + dp[i - k][k]

result = 0
for k in range(1, n + 1):
    result += dp[n][k]

print(result)

