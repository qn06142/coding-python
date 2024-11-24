l, r, t = (int(i) for i in input().split())
ans = 0
for x in range(l, r + 1):
    tx  = t - x
    y = x + 1
    z = tx - y
    if(z > r):
        y += z - r
        z = r
    if(y > z): continue
    if (z - y + 1) % 2 == 1:
        ans += (z - y) // 2
    if (z - y + 1) % 2 == 0:
        ans += (z - y + 1) // 2
print(ans)