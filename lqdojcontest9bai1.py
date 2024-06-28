def calculate_divisor_sums(limit):
    divisor_sum = [0] * (limit + 1)
    for i in range(1, limit + 1):
        for j in range(2 * i, limit + 1, i):
            divisor_sum[j] += i
    return divisor_sum

def preprocess_special_numbers(limit, max_x):
    divisor_sum = calculate_divisor_sums(limit)
    special_count = [[0] * (max_x + 1) for _ in range(limit + 1)]
    
    for x in range(1, max_x + 1):
        count = 0
        for n in range(1, limit + 1):
            if divisor_sum[n] > x:
                count += 1
            special_count[n][x] = count
    
    return special_count, divisor_sum

def count_special_numbers_in_range(L, R, X, special_count, divisor_sum):
    if X <= 10:
        if L == 1:
            return special_count[R][X]
        else:
            return special_count[R][X] - special_count[L-1][X]
    else:
        count = 0
        for i in range(L, R + 1):
            if divisor_sum[i] > X:
                count += 1
        return count

def process_queries(queries, special_count, divisor_sum):
    results = []
    for L, R, X in queries:
        results.append(count_special_numbers_in_range(L, R, X, special_count, divisor_sum))
    return results

# Input processing
import sys
input = sys.stdin.read
data = input().split()

Q = int(data[0])
queries = []
index = 1
for _ in range(Q):
    L = int(data[index])
    R = int(data[index + 1])
    X = int(data[index + 2])
    queries.append((L, R, X))
    index += 3

# Constants
LIMIT = 10 ** 5
MAX_X = 10

# Preprocess special numbers
special_count, divisor_sum = preprocess_special_numbers(LIMIT, MAX_X)

# Process the queries
results = process_queries(queries, special_count, divisor_sum)

# Output the results
for result in results:
    print(result)
