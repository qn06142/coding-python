n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
from sys import exit
pref = [0] * n
sum_b = 0
ans = True
cnt = 0

for i in range(n):
    cnt += a[i]
    pref[i] = cnt
    if a[i] < k:
        ans = False

for j in b:
    sum_b += j

if not ans or cnt > sum_b:
    print("Impossible")
    exit(0)

dp = [-1] * (sum_b + 1)
dp[0] = 0

for i in range(m):
    for j in range(sum_b, b[i] - 1, -1):
        if dp[j - b[i]] != -1:
            dp[j] = max(dp[j], dp[j - b[i]] + min(b[i], n))

for i in range(pref[n-1], sum_b + 1):
    if dp[i] >= k * n:
        print(i - pref[n-1])
        exit(0)

print("Impossible")