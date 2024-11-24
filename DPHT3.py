n = int(input())
class triplet:
	def __init__(self, y, x, z):
		self.x = x
		self.y = y
		self.z = z
a = [0] + sorted([triplet(*map(int, input().split())) for i in range(0, n)], key = lambda x: x.x)
from bisect import bisect
def bsearch(u, v, x):
	return bisect(a[1:], x, hi = v, lo = u, key = lambda x: x.x) 
f = [0] * (n + 5)
f[1] = a[1].z

for i in range(2, n + 1):
	t = bsearch(1, i-1, a[i].y)
	f[i] = max(f[i-1], f[t] + a[i].z)
print(f[n])