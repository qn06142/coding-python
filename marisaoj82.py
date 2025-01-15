import math
a = []
for i in range(0, int(math.ceil(math.log(10 ** 30, 2)) + 1)):
    for j in range(0, int(math.ceil(math.log(10 ** 30, 3)) + 1)):
        for k in range(0, int(math.ceil(math.log(10 ** 30, 5)) + 1)):
            a.append(pow(2, i) * pow(3, j) * pow(5, k))
a.sort()

def is_hamming(x):
    for i in [2, 3, 5]:
        while x % i == 0:
            x //= i
    return x == 1
from bisect import bisect_left
for i in range(0, int(input())):
    m = int(input())
    ind = bisect_left(a, m)
    if ind == len(a) or not is_hamming(m):
        print(-1)
    else:
        print(ind + 1)