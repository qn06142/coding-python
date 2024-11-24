import random

# Parameters
n = 100000
q = 100000

# Generate the array with random values between 1 and 1e9
array = [random.randint(1, 1000000000) for _ in range(n)]

# Generate the queries with random values of k (1 <= k <= ceil(n/2))
queries = [random.randint(1, (n + 1) // 2) for _ in range(q)]

# Output the generated test case
print(n)
print(" ".join(map(str, array)))
print(q)
for query in queries:
    print(query)
