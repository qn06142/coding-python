n = int(input())
from math import ceil, floor
d1 = abs(n - ceil(n / 10) * 10)
d2 = abs(n - floor(n / 10) * 10)
if d1 > d2:
    print(floor(n / 10) * 10)
else:
    print(ceil(n / 10) * 10)