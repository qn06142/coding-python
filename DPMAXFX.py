N = 10**5
a = [0] * (N + 1)
f = [[0] * (N + 1) for _ in range(3)]

n = int(input())
for i, itm in enumerate(input().split(), start = 1):
    a[i] = int(itm)

f[0][1] = a[1]
f[1][2] = f[0][1] + 2 * a[2]
f[0][2] = max(f[0][1], a[2])

for i in range(3, n + 1):
    f[2][i] = f[1][i - 1] + 3 * a[i]
    f[1][i] = max(f[1][i - 1], f[0][i - 1] + 2 * a[i])
    f[0][i] = max(f[0][i - 1], a[i])

res = -1e18
for i in range(3, n + 1):
    res = max(f[2][i], res)

print(res)
