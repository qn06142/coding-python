from math import comb

MOD = int(1e9 + 7)

def calculate_total_score(N):
    if N == 1:
        return 0  # No switches exist if there's only one machine.

    fact = [1] * (N + 1)

    # Precompute factorials modulo MOD
    for i in range(2, N):
        fact[i] = fact[i - 1] * i % MOD

    total_score = 0

    for k in range(1, N):
        # Compute the number of permutations contributing to score `k`
        Ck = comb(N - 1, k)  # Using math.comb to compute binomial coefficient
        term = Ck * fact[N - 1 - k] % MOD * k % MOD
        total_score = (total_score + term) % MOD

    # Special case for k = N-1
    total_score = (total_score + fact[N - 1]) % MOD

    return total_score

# Input
N = int(input().strip())

# Output
print(calculate_total_score(N))
