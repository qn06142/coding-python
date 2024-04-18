import math

with open('calc.inp', 'r') as f:
    b, n = map(int, f.readline().split())

a = 1
k = b
i = 2
while i * i <= k:
    if k % i == 0:
        d = 0
        while k % i == 0:
            k /= i
            d += 1
        if d % 2 != 0:
            a *= i
    i += 1
a *= k
x = round(math.sqrt(a * b))
dem = 1
i = 1
while i * i * a < b:
    p = x * i * n
    if p % b == 0:
        dem += 1
        if n > p / b:
            dem += 1
    i += 1

with open('calc.out', 'w') as f:
    f.write(str(dem))
