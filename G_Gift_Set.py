from math import ceil
ans = 0
def count(t, cnt):
    ans += cnt
    if t:
        x -= a * cnt
        y -= b * cnt
    else:
        x -= b * cnt
        y -= a * cnt
for i in range(0, int(input())):
    ans = 0
    x, y, a, b = (int(i) for i in input().split())
    if a > b:
        a, b = b, a
    if x >= y:
        x, y = y, x

    d = b - a
    count(1, min(ceil((y - x) / d), x // a, y // b))
    count(0, min(x // (a + b), y // (a + b)))    
    count(1, min(x // (a + b), y // (a + b)))
    if x >= b and y >= a:
        ans += 1
    print(ans)