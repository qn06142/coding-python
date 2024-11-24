n = int(input())

a = tuple(int(i) for i in input().split())

dp = [[0, 0] for i in range(0, n + 1)]
dp[0] = [0, 0]
for i in range(1, n + 1):
    dp[i][0] = max(dp[i - 2]) + a[i - 1]
    dp[i][1] = dp[i - 1][0] + a[i - 1]
print(max(dp[n]))