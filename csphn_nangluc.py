n, k = (int(i) for i in input().split())
a = [0] + list(int(i) for i in input().split())
from itertools import accumulate
pref = [0] + list(accumulate(a))
l = 0
r = 1
ans = 0
while r <= n :
    if pref[r] - pref[l] >= k:
        ans = max(ans, (pref[r]  - pref[l]) // (r - l))
        l += 1
    else:
        r += 1
print(ans)