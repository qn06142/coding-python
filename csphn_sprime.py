def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def generate_superprimes(start, end):
    primes = []
    superprimes = []
    for i in range(start, end+1):
        if is_prime(i):
            primes.append(i)
            if is_prime(len(primes)):
                superprimes.append(i)
    return superprimes

print(generate_superprimes(2, 19))
