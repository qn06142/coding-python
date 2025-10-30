import sys
from collections import Counter

def fact(n, p):
    res = 0
    denom = p
    while denom <= n:
        res += n // denom
        denom *= p
    return res

def calc(s):
    n = len(s)
    counts = Counter(s)
    v2 = fact(n, 2)
    v5 = fact(n, 5)
    for cnt in counts.values():
        if cnt > 1:
            v2 -= fact(cnt, 2)
            v5 -= fact(cnt, 5)
    return min(v2, v5)

data = sys.stdin.read().strip().split()
if not data:
    print(0)
else:
    s = data[0].strip()
    print(calc(s))
