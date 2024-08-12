def precompute_factorials(max_n, p):
    fact = [1] * (max_n + 1)
    inv_fact = [1] * (max_n + 1)
    
    # Compute all factorials % p
    for i in range(2, max_n + 1):
        fact[i] = fact[i - 1] * i % p
    
    # Compute inverses using Fermat's Little Theorem
    inv_fact[max_n] = pow(fact[max_n], p - 2, p)
    for i in range(max_n - 1, 0, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p

    return fact, inv_fact

def compute_combination(n, k, p, fact, inv_fact):
    if k > n:
        return 0
    return fact[n] * inv_fact[k] % p * inv_fact[n - k] % p

def solve_queries(queries, p):
    max_n = max(n for n, k in queries)
    fact, inv_fact = precompute_factorials(max_n, p)
    
    results = []
    for n, k in queries:
        result = compute_combination(n, k, p, fact, inv_fact)
        results.append(result)
    
    return results

# Read input
import sys
input = sys.stdin.read
data = input().strip().split()

t = int(data[0])
p = int(data[1])
queries = []

index = 2
for _ in range(t):
    n = int(data[index])
    k = int(data[index + 1])
    queries.append((n, k))
    index += 2

results = solve_queries(queries, p)
for res in results:
    print(res)