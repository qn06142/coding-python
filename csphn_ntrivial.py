inp = [int(i) for i in input().split()]
numberos = [i for i in range(inp[0], inp[1] + 1)]
from math import sqrt
from math import ceil
def trival(num):
    tmp = []
    for i in range(1, num):
        if num % i == 0:
            tmp.append(i)
    return sum(tmp)/num
def sieve(n):
    primes = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (primes[p] == True):
            for i in range(p * p, n+1, p):
                primes[i] = False
        p += 1
    prime_numbers = [p for p in range(2, n) if primes[p]]
    return prime_numbers
primes1 = sieve(inp[1])
primes1.reverse()
flag = False
numberostest = []
for i in primes1:
    if i in numberos:
        numberostest.append(i)
        flag = True
        break
if not flag:
    triviality = [trival(i) for i in numberos]
    indices = [i for i, x in enumerate(triviality) if x == min(triviality)]
    for i in indices:
        numberostest.append(numberos[i])
print(min(numberostest)%123456789)
