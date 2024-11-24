a, b, c = (int(i) for i in input().split())
from math import gcd
print(gcd(abs(a - b), abs(b - c)))