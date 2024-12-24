mod = 10 ** 9 + 7
from math import comb
for _ in range(0, int(input())):
    x, y = (int(i) for i in input().split())
    print(comb(x + y, x) % mod)