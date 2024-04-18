n = int(input())
a = [0] + [int(i) for i in input().split()]
f = [0]*1000005
f[1] = a[1]
f[2] = f[1] + a[2]
for i in range(1, n+1):
	f[i] = max(f[i - 3] + a[i-1] + a[i], max(f[i-2] + a[i], f[i-1]))
cnt = 0
ans = 1e9
def trace(t, i):
    global ans, cnt
    if t == 0 or i == 0:
        ans = min(ans, cnt)
        cnt -= 1
        return
    if t == f[i - 1]:
        i -= 1
        trace(t, i)
    elif t == f[i - 2] + a[i]:
        cnt += 1
        i -= 2
        trace(t - a[i + 2], i)
    elif t == f[i - 3] + a[i - 1] + a[i]:
        cnt += 2
        i -= 3
        trace(t - a[i + 2] - a[i + 3], i)
trace(f[n], n)
print(ans, f[n])