n, m = (int(i) for i in input().split())
a = [int(i) for i in input().split()]

def check(x):
    max_ = 0
    min_ = 1e18
    ans = 0
    for i in a:
        max_ = max(max_, min(x, i))
        min_ = min(min_, min(x, i))
        ans += min(x, i)
    print(ans, max_ - min_)
    return ans

l = 0
r = sum(a)
while l <= r:
    mid = (l + r) // 2
    if(check(mid) >= m):
        r = mid - 1
    else:
        l = mid + 1
print(l, r)