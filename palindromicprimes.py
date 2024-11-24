def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    p = 2
    while (p * p <= n):
        if (is_prime[p]):
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    return [p for p in range(2, n + 1) if is_prime[p]]

def is_prime(num, prime_set):
    if num < 2:
        return False
    if num in prime_set:
        return True
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def symmetric_primes(n):
    primes = sieve_of_eratosthenes(n)
    prime_set = set(primes)
    symmetric_primes = [p for p in primes if is_prime(int(str(p)[::-1]), prime_set)]
    return symmetric_primes

n = int(input())
result = symmetric_primes(n)
print(" ".join(map(str, result)))
