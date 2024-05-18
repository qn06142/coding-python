n, k = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
if k >= 4:
    raise ValueError
from itertools import combinations
ans = 0
for i in combinations(a, k):
    for j in combinations(b, k):
        tmp = 0
        for a in zip(i, j):
            tmp += a[0] * a[1]
        ans = max(ans, tmp)
print(ans)