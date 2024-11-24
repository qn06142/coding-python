n = int(input())
a = [0] + [int(i) for i in input().split()]
l = [0] * (n + 5)
r = [0] * (n + 5)
for i in range(1, n + 1):
	l[i] = 1
	for j in range(1, i):
		if a[j] < a[i]: l[i] = max(l[i], l[j] + 1)
for i in range(n, 0, -1):
	r[i] = 1
	for j in range(n, i, -1):
		if a[j] < a[i]:
			r[i] = max(r[i], r[j] + 1)
res = 0
for i in range(1, n + 1):
	res = max(res, 2 * min(l[i], r[i]) - 1)
print(res)