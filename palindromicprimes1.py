def sieve(n):
    is_prime = [True] * (n + 1)
    p = 2
    while (p * p <= n):
        if (is_prime[p]):
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    return [p for p in range(2, n + 1) if is_prime[p]]
n = int(input())
primes = list(sieve(n))
check = set(primes)
count = 0
for i in primes[4:]:
    if (str(i)[::-1] == str(i)):
        count += 1
print(count)