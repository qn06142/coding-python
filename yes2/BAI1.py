from math import sqrt
from bisect import bisect_right

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def find_kth_divisor(n, k):
    factors = prime_factors(n)
    divisors = set([1])
    for factor in factors:
        divisors.update([factor * divisor for divisor in divisors])
    divisors = sorted(list(divisors))
    if k <= len(divisors):
        return divisors[k - 1]
    else:
        return -1

n, k = (int(i) for i in input().split())
print(find_kth_divisor(n, k))
