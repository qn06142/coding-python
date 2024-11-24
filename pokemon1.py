l = 0
r = 100
ans = -1
a, b = (int(i) for i in input().split())

while l <= r:
    mid = (l + r) // 2
    if a * (3 ** mid) > b * (2 ** mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
