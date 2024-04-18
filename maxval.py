n = int(input())
a = [int(i) for i in input().split()]
ans = 0
from bisect import bisect_right
a.sort()
for j in range(n - 1, -1, -1):
    if ans >= a[j]:
        break
    if a[j] == a[j + 1]:
        continue
    for i in range(2 * a[j], a[n - 1] + a[j] + 1, a[j]):
        tmp = bisect_right(a, i)
        ans = max(ans, a[tmp - 1] % a[j])
print(ans)