import sys

MAX_PRIME = int(1e6)
primes = []

# Sieve of Eratosthenes to generate primes
def sieve():
    is_prime = [True] * (MAX_PRIME + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(MAX_PRIME**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, MAX_PRIME + 1, i):
                is_prime[j] = False
    for i in range(2, MAX_PRIME + 1):
        if is_prime[i]:
            primes.append(i)

# Function to calculate power
def power(base, exp):
    result = 1
    while exp:
        if exp % 2 == 1:
            result *= base
        base *= base
        exp //= 2
    return result

def main():
    n, k = map(int, sys.stdin.readline().split())
    
    sieve()
    result = -1

    # Iterate over all triplets of consecutive primes
    for i in range(len(primes) - 2):
        p1, p2, p3 = primes[i], primes[i + 1], primes[i + 2]

        # Try all possible powers t1, t2, t3
        for t1 in range(1, sys.maxsize):
            m1 = power(p1, t1)
            if m1 > n:
                break

            for t2 in range(1, sys.maxsize):
                m2 = m1 * power(p2, t2)
                if m2 > n:
                    break

                for t3 in range(1, sys.maxsize):
                    m = m2 * power(p3, t3)
                    if m > n:
                        break

                    # Check if the number of divisors matches k
                    divisors = (t1 + 1) * (t2 + 1) * (t3 + 1)
                    if divisors == k:
                        result = max(result, m)

    print(result)

if __name__ == "__main__":
    main()

