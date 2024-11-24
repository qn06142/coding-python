n = int(input())
a = [2, 4, 7]

for i in range(3, n-1):
	a.append(a[i-1] + a[i-2] + a[i-3])
print(a[-1])