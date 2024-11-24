def check(mid, n, m, k):
    cnt = 0
    for i in range(1, n+1):
        cnt += min(mid//i, m)
    return cnt < k

def solve(n, m, k):
    l = 1
    r = n*m+1
    while r > l:
        mid = (l+r)//2
        if check(mid, n, m, k):
            l = mid+1
        else:
            r = mid
    return l

n, m, k = map(int, input().split())
print(solve(n, m, k))
