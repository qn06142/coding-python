import math

def sieve_of_eratosthenes(limit):
    is_prime = [True] * (limit + 1)
    p = 2
    while (p * p <= limit):
        if (is_prime[p] == True):
            for i in range(p * p, limit + 1, p):
                is_prime[i] = False
        p += 1
    prime_numbers = [p for p in range(2, limit + 1) if is_prime[p]]
    return prime_numbers

def count_super_beautiful_numbers(n):
    limit_q = int(n ** (1/3)) + 1
    prime_numbers = sieve_of_eratosthenes(limit_q)
    count = 0
    for i in range(len(prime_numbers)):
        q = prime_numbers[i]
        q_cubed = q ** 3
        if q_cubed > n:
            break
        for j in range(i):
            p = prime_numbers[j]
            if p * q_cubed <= n:
                count += 1
            else:
                break
    return count

# Ví dụ sử dụng
n = 10 ** 18
result = count_super_beautiful_numbers(n)
print(f"Số lượng số siêu đẹp ≤ {n} là {result}")
