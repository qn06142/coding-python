import math

m = int(input())
n = int(input())
def f(q):
    p = (n + q) - (m % (n + q))
    if p >= m:
        return 0
    return ((m - p - 1) // (n + q)) + 1

res = 0
for q in range(1, n):
    res += f(q)

print(res)

