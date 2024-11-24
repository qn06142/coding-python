from math import sqrt
maxn = 10000 + 5
R = 1000000000 + 7
n = int(input())
a = [0] + [int(input()) for i in range(0, n)] + [0]
f = [1 for i in range(0, maxn)]
for i in range(1, n + 1):
	for j in range(i - 1, max(1, i - 10) - 1, -1):
		if abs(a[i] - a[j]) > 0 and int(sqrt(abs(a[i] - a[j]))) ** 2 == abs(a[i] - a[j]):
			f[i] = max(f[i], f[j] + 1)
ans = max(f)
print(ans)