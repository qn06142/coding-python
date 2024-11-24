MOD = 10**9 + 7

def count_paths(n, m):
    dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(n+1):
        for j in range(m+1):
            if i+1 <= n:
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD
            if j+1 <= m:
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD
            if i+1 <= n and j+1 <= m:
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD
    return dp[n][m]

n, m = map(int, input().split())
print(count_paths(n, m))
