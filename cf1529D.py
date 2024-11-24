N = 10**6 + 10
MOD = 998244353

n = int(input())
dp = [0] * (N+1)
S = 1

for i in range(1, n+1):
    for j in range(i+i, n+1, i):
        dp[j] += 1

dp[0] = S = 1
for i in range(1, n+1):
    dp[i] = (dp[i] + S) % MOD
    S = (S + dp[i]) % MOD

print(dp[n])
