n, k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
from itertools import accumulate
pref = list(accumulate(a))
pref.append(0)
ans = 1e18
for i in range(0, n - k):
    newa = a[:i] + a[i + k:]
    best = 0
    for i in range(0, n - 2 * k):
        sum_ = pref[i + k] - pref[i]
        best = max(sum_, best)
        print(sum_, i)
    print(*newa)
    ans = min(ans, best)
print(ans)