n = int(input())
a = [0 for i in range(0, n + 5)]
b = [0 for i in range(0, n + 5)]
for i in range(1, n + 1):
	a[i], b[i] = map(int, input().split())
f = [[0 for i in range(0, n + 2)] for i in range(0, n + 2)]
for i in range(1, n+1):
	for j in range(1, n + 1):
		if a[i] == b[j] == 1 or a[i] != b[j]:
			f[i][j] = f[i-1][j-1] + 1
		else:
			f[i][j] = max(f[i-1][j], f[i][j - 1])
print(f[n][n])