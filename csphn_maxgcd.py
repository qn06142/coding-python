n = int(input())
a = list(int(i) for i in input().split())
prefix = [0 for i in range(0, n + 2)]
suffix = [0 for i in range(0, n + 2)]
prefix[1] = a[0]
from math import gcd
for i in range(2, n + 1):
    prefix[i] = gcd(prefix[i - 1], a[i - 1])
suffix[n] = a[n - 1]
for i in range(n - 1, 0, -1):
    suffix[i] = gcd(suffix[i + 1], a[i - 1])
ans = max(suffix[2], prefix[n-1])
for i in range(2, n):
    ans = max(ans, gcd(prefix[i - 1], suffix[i + 1]))
print(ans)