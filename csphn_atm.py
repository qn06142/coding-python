n, m = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
s = [int(i) for i in input().split()]
theset = set()
from itertools import combinations
for i in range(1, n+1):  # change here
    for i in combinations(a, i):
        theset.add(sum(i))
ans = 0
for i in s:
    ans += (i in theset)
print(ans)  # print the number of successful tests
