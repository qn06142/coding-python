n = int(input())
t = [0] + [int(i) for i in input().split()] + [0]
r = [0] + [int(i) for i in input().split()] + [0]
f = [0] * 1000001
f[1] = t[1]
for i in range(2, n+1):
	f[i] = min(f[i-2] + r[i-1], f[i-1] + t[i])
print(f[n])
