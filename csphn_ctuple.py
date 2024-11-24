a, b, c, d, x = tuple(int(i) for i in input().split())
A = [0] * (10 ** 6 + 10000)
B = A.copy()
for i in range(1, a + 1):
	for j in range(1, b + 1):
		A[i * j] += 1
for i in range(1, c + 1):
	for j in range(1, d + 1):
		B[i*j] += 1
for i in range(1, 10 ** 6 + 1):
	B[i] += B[i-1]
maxx = 10 ** 6

ans = 0
for i in range(1, 10 ** 6 + 1):
	ans += A[i] * B[min(x // i, maxx)]
print(ans)
