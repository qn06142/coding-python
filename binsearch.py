from bisect import bisect_left
n, q = tuple(int(i) for i in input().split())
a = tuple(int(i) for i in input().split())
queries = tuple(int(input()) for i in range(0, q))
for i in queries:
	tmp = bisect_left(a, i)
	if tmp >= n:
		print(-1)
		continue
	if a[tmp] != i:
		print(-1)
	else:
		print(i)