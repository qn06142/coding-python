import sys
import itertools
from collections import defaultdict

def calc(n, a):
    count = defaultdict(int)

    for prob in a:
        prob.sort()

        for k in range(1, 6):
            for subset in itertools.combinations(prob, k):
                count[subset] += 1

    res = 0
    for subset, f in count.items():
        if f >= 2:
            sign = 1 if (len(subset) % 2 == 1) else -1
            res += sign * (f * (f - 1) // 2)

    tot = n * (n - 1) // 2
    ans = tot - res
    return ans
tmp = sys.stdin.read().split()
n = int(tmp[0])
a = []
idx = 1
for _ in range(n):

    prob = list(map(int, tmp[idx:idx+5]))
    idx += 5
    a.append(prob)

result = calc(n, a)
print(result)