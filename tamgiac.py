from bisect import bisect_left

n, s = map(int, input().split())
x, y = map(abs, map(int, input().split()))
a = list(map(int, input().split()))
ps = [0 for _ in range(n)]
a.sort()

for i in range(n):
    if i > 0:
        ps[i] = ps[i - 1] + (a[i] - pt) * y / 2
    else:
        ps[i] = 0
    pt = a[i]

ans = 0
for i in range(n):
    ans += bisect_left(ps, ps[i] - s)
print(ans)
