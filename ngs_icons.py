from math import ceil
n = int(input())
a = []
for i in range(1, n + 1):
    a.append((i, ceil(n / i)))
print(*min(a, key=lambda x: sum(x)))