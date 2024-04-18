for _ in range(0, int(input())):
	n = int(input())
	a = [0] + [int(i) for i in input().split()]
	f = [0]*1000005
	f[1] = a[1]
	for i in range(2, n+1):
		f[i] = max(f[i-2] + a[i], f[i-1])
	print(f[n])

