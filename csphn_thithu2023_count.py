n, m = tuple(int(i) for i in input().split())

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
a.sort()
from bisect import bisect_left
for i in b:
    print(i - bisect_left(a, i))