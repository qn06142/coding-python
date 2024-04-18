def count_piggy_banks(N, M, operations, Q, queries):
    piggy_banks = [0]*N
    for L, R in operations:
        for i in range(L-1, R):
            piggy_banks[i] += 1
    results = []
    for x in queries:
        count = sum(1 for money in piggy_banks if money >= x)
        results.append(count)
    return results

# Test the function
N, M = tuple(int(i) for i in input().split())
operations = [tuple(int(i) for i in input().split()) for i in range(0, M)]
Q = int(input())
queries = tuple(int(input()) for i in range(0, Q))
print(*count_piggy_banks(N, M, operations, Q, queries), sep = "\n")
