for _ in range(0, int(input())):
	n = int(input())
	a = [0] + [int(i) for i in input().split()] + [0] * 100
	f = [0]*1000005
	for i in range(n, 0, -1):
		f[i] = max(max(f[i], f[i + 2] + a[i]), max(f[i + 4] + a[i] + a[i + 1], f[i + 6] + a[i] + a[i + 1] + a[i + 2]))
	print(f[1])