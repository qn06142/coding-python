from math import floor
def check(x):
	t = a[1] + x
	d = 1
	for i in range(2, n+1):
		if a[i] > (t+x):
			d += 1
			t = a[i] + x
	t = a[2] + x
	d1 = 1
	for i in range(3, n+2):
		if a[i] > (t+x):
			d1 += 1
			t = a[i] + x
	return min(d, d1) <= k
def solve(l, r):
	ans = 0
	while l <= r:
		mid = floor((l+r)/2)
		if check(mid):
			ans = mid
			r = mid - 1
		else:
			l = mid+1
	return ans
n = int(input())
a = [0] + sorted(int(input()) for i in range(0, n))
k = int(input())
a.append(a[1] + 10 ** 6)
print(solve(1, 1e6))