n, q  = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]
queries = tuple(tuple(int(i) for i in input().split()) for i in range(0, q))
from itertools import accumulate
prefix = list(accumulate(1- i % 2 for i in a))
for i in queries:
	print(prefix[i[1]-1 if i[1] > 1 else 0] - prefix[i[0]-2 if i[0] > 1 else 0])