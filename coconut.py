t = int(input())
n = int(input())
monkeyst1 = list(tuple(int(i) for i in input().split()) for i in range(0, n))
m = int(input())
monkeyst2 = list(tuple(int(i) for i in input().split()) for i in range(0, m))
monkeyst1.sort(reverse = True)
monkeyst2.sort(reverse = True)

def check(x):
    coconutsharv = 0
    coconutsproc = 0
    for i in monkeyst1:
        if i[0] + i[1] > x:
            break
        else:
            coconutsharv += (x - i[0]) // i[1]
    for i in monkeyst2:
        if i[0] + i[1] > (t - x):
            break
        else:
            coconutsproc += ((t - x) - i[0]) // i[1]
    return coconutsharv, coconutsproc
"""
while True:
    print(check(int(input())))
"""
l = 0
r = t
while l < r:
    mid = (l + r) // 2
    #print(l, r, mid)
    coconutsharv, coconutsproc = check(mid)
    if coconutsharv >= coconutsproc:
        r = mid
    else:
        l = mid + 1
print(l)