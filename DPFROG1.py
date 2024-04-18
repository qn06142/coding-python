n = int(input())
a = [0] + [int(i) for i in input().split()] + [0] * 100
f = [0]*1000005
f[1] = 0
f[2] = abs(a[1] - a[2])
for i in range(3, n + 1):
	f[i] = min(f[i-1] + abs(a[i] - a[i-1]), f[i-2] + abs(a[i] - a[i-2])); 
print(f[n])
