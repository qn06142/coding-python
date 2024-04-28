
n, k = map(int, input().split())
MAXK = int(1e5)
mod = int(1e9 + 7)
dp = [0] * (MAXK + 1)
dq = [0] * (MAXK + 1)
dp[0] = 1
tmp = iter(int(i) for i in input().split())
for _ in range(n):
    a = next(tmp)
    for j in range(1, k + 1):
        dp[j] = (dp[j - 1] + dp[j]) % mod
    for j in range(k + 1):
        dq[j] = (dp[j] - (dp[j - a - 1] if j > a else 0)) % mod
    dp, dq = dq, dp

print(dp[k])

