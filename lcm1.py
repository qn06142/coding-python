def sieve(n):
    is_prime = [True] * (n + 1)
    p = 2
    while (p * p <= n):
        if (is_prime[p] == True):
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    prime_numbers = []
    for p in range(2, n + 1):
        if is_prime[p]:
            prime_numbers.append(p)
    return prime_numbers

def calculate_lcm(n):
    MOD = 10**9 + 7
    primes = sieve(n)
    lcm = 1
    
    for prime in primes:
        p = prime
        while p * prime <= n:
            p *= prime
        lcm = lcm * p % MOD
    
    return lcm

# Đọc giá trị n từ input
n = int(input().strip())
print(calculate_lcm(n))
