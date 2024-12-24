from fractions import Fraction
n, k = (int(i) for i in input().split())
print(sorted(Fraction(i, j) for i in range(1, n + 1) for j in range(1, n + 1))[k - 2])