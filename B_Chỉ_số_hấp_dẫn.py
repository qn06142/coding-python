import sys
input = sys.stdin.read
data = input().splitlines()

def mod_pow(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

p = int(data[0])  # The prime p
s = data[1]       # The string S
n = len(s)        # Length of the string S
q = int(data[2])  # Number of queries

queries = []
for i in range(3, 3 + q):
    l_, r_ = map(int, data[i].split())
    queries.append((l_ - 1, r_ - 1))  # Convert to 0-based indexing

# Precompute powers of 10 modulo p
powers_of_10 = [1] * (n + 1)
for i in range(1, n + 1):
    powers_of_10[i] = (powers_of_10[i - 1] * 10) % p

# Precompute prefix moduli
prefix_mod = [0] * (n + 1)
for i in range(n):
    prefix_mod[i + 1] = (prefix_mod[i] * 10 + int(s[i])) % p

# Function to compute if the number formed from s[l:r+1] is divisible by p
def is_good(l, r):
    # The number is (prefix_mod[r+1] - prefix_mod[l] * 10^(r-l+1)) % p
    num_mod = (prefix_mod[r + 1] - (prefix_mod[l] * powers_of_10[r - l + 1]) % p) % p
    return num_mod == 0

# Mo's algorithm: rearrange queries to minimize range modifications
block_size = int(n ** 0.5)
queries.sort(key=lambda x: (x[0] // block_size, x[1] if (x[0] // block_size) % 2 == 0 else -x[1]))

ans = 0
l, r = 0, -1

# Results for each query
results = [0] * q

# Process each query
for idx, (ql, qr) in enumerate(queries):
    while r < qr:
        r += 1
        if is_good(l, r):
            ans += 1
    while r > qr:
        if is_good(l, r):
            ans -= 1
        r -= 1
    while l < ql:
        if is_good(l, r):
            ans -= 1
        l += 1
    while l > ql:
        l -= 1
        if is_good(l, r):
            ans += 1
    results[idx] = ans

# Output results
sys.stdout.write("\n".join(map(str, results)) + "\n")
