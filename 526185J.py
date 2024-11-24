def process_queries(n, q, a, queries):
    results = []
    for U, V, x in queries:
        if U == 0:
            sorted_part = sorted(a[:x], reverse=V==1)
            result = sorted_part + a[x:]
        else:
            sorted_part = sorted(a[-x:], reverse=V==1)
            result = a[:-x] + sorted_part
        results.append(result)
    return results

n, q = map(int, input().split())
a = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(q)]

results = process_queries(n, q, a, queries)

for result in results:
    print(' '.join(map(str, result)))