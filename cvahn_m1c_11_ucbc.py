with open("UCBCD.inp", "r") as f:
	a = int(f.readline())
	b = tuple(map(int, f.readline().split()))
from math import gcd
from math import lcm
from functools import reduce
with open("UCBCD.out", "w") as f:
	f.write(str(reduce(gcd, b)) + '\n' + str(reduce(lcm, b)))