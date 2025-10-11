from bisect import bisect_left
def bsearch(a, x):
    pos = bisect_left(a, x)
    if pos == 0:
        return 0
    if pos == len(a):
        return -1
    before = a[pos - 1]
    after = a[pos]
    if after - x < x - before:
        return pos
    else:
        return pos - 1
def solve(n, l, r, a):
    a.sort()
    if r <= a[0]:
        return l
    if l >= a[n-1]:
        return r
    from math import ceil
    tmpL = (abs(l - a[bsearch(a, l)]), l)
    tmpR = (abs(r - a[bsearch(a, r)]), r)
    ans = (float('-inf'), None)
    for i in range(1, n):
        x = (a[i - 1] + a[i] + 1) // 2
        if x in range(l, r):
            ans = max(ans, (min(abs(x - a[i - 1]), abs(x - a[i])), x))
    
    return max(ans, tmpL, tmpR)[1]

n, l, r = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
print(solve(n, l, r, a))
