n, k = tuple(int(i) for i in input().split())
a = [0] + [int(i) for i in input().split()]
f = [0]*1000005
for i in range(1, n + 1):
	for j in range(i - 1, max(0, i - k) - 1, -1):
		f[i] = max(f[j] + a[i], f[i])
print(f[n])