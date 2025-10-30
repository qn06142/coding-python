import itertools
n, k = map(int, input().split())
a = list(int(input()) for i in range(0, n))
a.sort()
ans = 0
for j, i in enumerate(itertools.accumulate(a)):
    if i <= k:
        ans = max(ans, i)
print(ans)