import math
import bisect
import sys

def fast_input():
    return sys.stdin.readline().strip()

N_LIMIT = 10**18

PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

pairs = []

def search(prime_idx, current_x, current_sigma, max_exponent):

    pairs.append((current_x, current_sigma))

    if prime_idx >= len(PRIMES):
        return

    p = PRIMES[prime_idx]
    exponent = 1
    next_x = current_x 

    while exponent <= max_exponent:

        if next_x > N_LIMIT // p:
            break

        next_x *= p

        next_sigma_val = current_sigma * (exponent + 1)

        search(prime_idx + 1, next_x, next_sigma_val, exponent)

        exponent += 1

search(0, 1, 1, 60)

pairs.sort(key=lambda item: item[0])
final = []
max_sigma_seen = 0
for x, sigma in pairs:

    if sigma > max_sigma_seen:
        final.append((x, sigma))
        max_sigma_seen = sigma

final.sort(key=lambda item: item[0])

precomp = [item[0] for item in final]

T = int(fast_input())
res = []
for _ in range(T):
    n = int(fast_input())

    idx = bisect.bisect_right(precomp, n)

    best_x, best_sigma = final[idx - 1]
    res.append(f"{best_x} {best_sigma}")

print("\n".join(res))