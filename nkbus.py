from sys import stdin
inputs = iter(int(i) for i in stdin.read().split())
n, m = next(inputs), next(inputs)
f = [0] * (n + 2)
p = 0
a = []

for i in range(1, n + 1):
    t, k = next(inputs), next(inputs)
    f[i + 1] = f[i] + t

    for _ in range(k):
        x = next(inputs)
        a.append(max(0, x - f[i]))

    p += k

a.sort()
res = f[n + 1] + a[m - 1]
print(res)