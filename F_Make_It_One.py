import sys
import math
from functools import reduce
from math import gcd

def readints():
    return list(map(int, sys.stdin.buffer.read().split()))

data = readints()
if not data:
    sys.exit()
it = iter(data)
n = next(it)
a = [next(it) for _ in range(n)]

g_all = reduce(gcd, a)
if g_all != 1:
    print(-1)
    sys.exit()

MAXA = max(a)
freq = [0] * (MAXA + 1)
for x in a:
    freq[x] += 1

f = [0] * (MAXA + 1)
for d in range(1, MAXA + 1):
    s = 0
    for m in range(d, MAXA + 1, d):
        s += freq[m]
    f[d] = s

candidates = [d for d in range(1, MAXA + 1) if f[d] > 0]
if not candidates:
    print(-1)
    sys.exit()
candidates.sort(reverse=True)  

idx_of = {d: idx for idx, d in enumerate(candidates)}
m = len(candidates)

mulind = [[] for _ in range(m)]

val_at = candidates[:]  
by_val = {v: i for i, v in enumerate(val_at)}
max_val = MAXA

for i_j, v in enumerate(val_at):
    k = 2 * v
    while k <= max_val:
        if k in by_val:
            mulind[i_j].append(by_val[k])
        k += v

for i in range(1, n + 1):
    dp = [0] * m  

    for idx_j, v in enumerate(val_at):
        if f[v] < i:

            dp[idx_j] = 0
            continue

        total = math.comb(f[v], i)

        s = 0
        for m_idx in mulind[idx_j]:
            s += dp[m_idx]
        dp[idx_j] = total - s

    if 1 in by_val:
        idx1 = by_val[1]
        if dp[idx1] > 0:
            print(i)
            sys.exit()
    else:

        pass

print(-1)
