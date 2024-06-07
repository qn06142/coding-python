from fractions import Fraction as frac
a, b, c = int(input()), int(input()), int(input())
out = str(frac(max(a, b, c), min(a, b, c)))
if '/' not in out:
    print(int(out) + 1)
else:
    print(sum(int(i) for i in out.split(sep = '/')))