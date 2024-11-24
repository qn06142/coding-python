from math import ceil, sqrt
def cbrt(x): return x ** (1/3)
a, b, k = [int(i) for i in input().split()]
count = 0

x_start = ceil(sqrt(a))
x_end = int(sqrt(b))

y_start = ceil(cbrt(a))
y_end = int(cbrt(b))

for x in range(x_start, x_end + 1):
    x_squared = x ** 2
    if x_squared < a or x_squared > b:
        continue
    for y in range(y_start, y_end + 1):
        y_cubed = y ** 3
        if y_cubed < a or y_cubed > b:
            continue
        if abs(x_squared - y_cubed) <= k:
            count += 1

print(count)
