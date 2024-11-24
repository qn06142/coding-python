a = [1, 1]
n = int(input())
if n > 2:
	for i in range(1, n - 1):
		a.append(a[i] + a[i-1])
	print(a[-1])
else:
	print(1)