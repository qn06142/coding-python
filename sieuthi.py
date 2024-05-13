n, k = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
a.sort()
s = 0
s = sum(a)
for i in range(k-1, n, k):
	s -= a[i]
print(s)