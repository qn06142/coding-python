import math
from functools import reduce

def gcd_list(numbers):
    return reduce(math.gcd, numbers)

def process_queries(queries):
    results = []
    
    for query in queries:
        n, k, a = query
        overall_gcd = gcd_list(a)
        
        if k % overall_gcd == 0:
            results.append("YES")
        else:
            results.append("NO")
    
    return results

# Input processing
T = int(input().strip())
queries = []

for _ in range(T):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    queries.append((n, k, a))

# Process and print the results
results = process_queries(queries)
for result in results:
    print(result)
