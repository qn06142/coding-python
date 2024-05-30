from collections import Counter
from math import sqrt

def prime_factors(n):
    i = 2
    factors = Counter()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors[i] += 1
    if n > 1:
        factors[n] += 1
    return factors

def count_divisors(n):
    factors = prime_factors(n)
    divisors = 1
    for factor in factors.values():
        divisors *= (factor + 1)
    return divisors

N = int(input())
factors = prime_factors(N)
divisors = count_divisors(N)
out = ''
for factor, power in factors.items():
    out += str(factor) + ' ' + str(power) + '\n'
print(out)