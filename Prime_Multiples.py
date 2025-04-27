import itertools, math
n, k = map(int, input().split())
print(sum((n//math.prod(c) if len(c)%2==1 else -(n//math.prod(c))) for p in [list((int(x) for x in input().split()))] for c in itertools.chain.from_iterable(itertools.combinations(p, j) for j in range(1, k+1))))
