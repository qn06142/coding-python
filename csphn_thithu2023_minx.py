from math import lcm, gcd
#
for _ in range(0, int(input())):
    a, b, c = (int(i) for i in input().split())
    print(lcm(b // gcd(a, b), c // gcd(b, c), a // gcd(c, a)))