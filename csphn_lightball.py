from bisect import bisect_left, bisect_right
def process(a, b, c):
    n1 = len(a)
    n2 = len(b)
    n3 = len(c)
    best = []
    for i in b:
        tmp = bisect_left(a, i)
        tmp1 = bisect_right(c, i) - 1
        if tmp != n1 and tmp1 != n3:
            tmp = a[tmp]
            tmp1 = c[tmp1]
            best.append((tmp - i) ** 2 + (i - tmp1) ** 2 + (tmp - tmp1) ** 2)
            

    if not best:
        return 1e18
    return min(best)

m, n, p = tuple(int(i) for i in input().split())
a = list(int(i) for i in input().split())
b = list(int(i) for i in input().split())
c = list(int(i) for i in input().split())
a.sort()
b.sort()
c.sort()
print(min(process(a,b,c),process(a,c,b),process(b,a,c),process(b,c,a),process(c,b,a),process(c,a,b)))
