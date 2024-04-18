MAXN = 10**6 + 1
R = 10**9 + 7
a = [0] * MAXN
f = [0] * MAXN

n, k = map(int, input().split())
a[1] = f[1] = 2

for i in range(2, k + 1):
    a[i] = (2 * a[i - 1]) % R
    f[i] = (f[i - 1] + a[i]) % R

a[k] -= 1
f[k] -= 1

for i in range(k + 1, n + 1):
    a[i] = (f[i - 1] - f[i - k - 1]) % R
    f[i] = (f[i - 1] + a[i]) % R

print(a[n] % R)
