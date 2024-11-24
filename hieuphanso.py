a, b = tuple(int(i) for i in input().split())
c, d = tuple(int(i) for i in input().split())
from math import gcd, lcm
y = lcm(b, d)
a *= y // b
c *= y // d
x = a - c
print(x // gcd(x, y), y // gcd(x, y))