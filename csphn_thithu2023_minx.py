from math import lcm, gcd
#
for _ in range(0, int(input())):
    a, b, c = tuple(int(i) for i in input().split())
    print(lcm(a / (gcd(a, b), b / gcd(b, c), c / gcd(c, a))))