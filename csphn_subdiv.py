from collections import defaultdict
from itertools import accumulate
n, k = map(int, input().split())
pref = [0] + list(accumulate((int(i) for i in input().split())))
cnt = defaultdict(int)
cnt[0] = 1
ans = 0

for i in range(1, n + 1):
    ans += cnt[pref[i] % k]
    cnt[pref[i] % k] += 1

print(ans)
