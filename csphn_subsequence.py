n = int(input())
a = tuple(int(i) for i in input().split())
dp = [0 for i in range(0, n)]
from collections import defaultdict
dp1 = defaultdict(lambda: 0)
curr = 1
mod = 10 ** 9 + 7
for i in range(0, n):
    dp[i] = (curr - dp1[a[i]] + mod) % mod
    curr += dp[i]
    curr %= mod
    dp1[a[i]] += dp[i]
    dp1[a[i]] %= mod
print(sum(dp) % mod)