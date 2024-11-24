import math
from functools import reduce
from itertools import combinations

def lcm(a, b):
    return a * b // math.gcd(a, b)

def count_divisibles(l, r, d):
    return r // d - (l - 1) // d

def solve(n, l, r, a):
    result = 0
    for k in range(1, n + 1):
        for subset in combinations(a, k):
            lcm_val = reduce(lcm, subset)
            if lcm_val > r:
                continue
            cnt = count_divisibles(l, r, lcm_val)
            if k % 2 == 1:
                result += cnt
            else:
                result -= cnt
    return (r - l + 1) - result

n, l, r = map(int, input().split())
a = list(map(int, input().split()))

print(solve(n, l, r, a))