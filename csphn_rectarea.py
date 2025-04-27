import itertools
n = int(input())
rects = [tuple(int(i) for i in input().split()) for i in range(0, n)]
combs = list(itertools.chain(*(itertools.combinations(rects, i) for i in range(1, n + 1))))
ans = 0
def calc(rects):
    x1 = max(r[0] for r in rects)
    y1 = max(r[1] for r in rects)
    x2 = min(r[2] for r in rects)
    y2 = min(r[3] for r in rects)
    if x1 >= x2 or y1 >= y2:
        return 0
    return (x2 - x1) * (y2 - y1)
for i in combs:
    if(len(i) % 2):
        ans += calc(i)
    else:
        ans -= calc(i)
print(ans)