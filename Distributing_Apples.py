import math
x, y = map(int, input().split())
print(math.comb(x + y + 1, y - 1))