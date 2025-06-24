import math
input()
print(sum(x == math.isqrt(x) ** 2 for x in (int(i) for i in input().split())))
