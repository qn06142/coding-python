N = 10 ** 4
n, k = tuple(int(i) for i in input().split())
f = [1] * N

for i in range(1, n + 1):
	f[i] = (f[i - 1] + f[max(0, i - k - 1)]) % 1000000
print(f[n])