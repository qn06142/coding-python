from bisect import bisect_left, bisect_right
n, q = tuple(int(i) for i in input().split())
a = tuple(int(i) for i in input().split())
tmp = bisect_right(a, q) - bisect_left(a, q)
print(tmp)
