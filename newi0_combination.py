n, k = map(int, input().split())
from itertools import combinations
from math import prod, sqrt
ans = 0
for i in combinations(range(1, n + 1), k) :
    print(*i)
    if prod(i) == int(sqrt( prod(i))) ** 2:
        ans += 1
print(ans)