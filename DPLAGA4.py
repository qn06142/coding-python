N = 10 ** 6
mod = 998244353
f =[0 for i in range(0, N+5)]
f1 = [0 for i in range(0, N+5)]
n = int(input())
f[0] = 1
f[1] = 1
f[2] = 5
for i in range(3, N + 1):
	f[i] = (4 * f[i - 2] + 2 * f[i - 3] + f[i - 1]) % mod
f1[0] = 0
f1[1] = 0
f1[2] = 12
for i in range(3, n + 1):
	f1[i] = (f1[i - 1] + 4 * (3 * f[i - 2] + f1[i - 2]) + 2 * (6 * f[i - 3] + f1[i - 3])) % mod
print(f1[n])