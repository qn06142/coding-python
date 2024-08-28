def process_queries(n, q, a, queries):
    results = []
    for x in queries:
        sorted_part = sorted(a[:x])
        result = sorted_part + a[x:]
        results.append(result)
    return results

n, q = map(int, input().split())
a = list(map(int, input().split()))
queries = [int(input()) for _ in range(q)]

results = process_queries(n, q, a, queries)

for result in results:
    print(' '.join(map(str, result)))
