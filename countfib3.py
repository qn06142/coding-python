def fib(n):
    return n // 4

with open("fibocnt.inp", "r") as f:
    queries = [int(f.readline()) for _ in range(int(f.readline()))]

results = {}
for query in queries:
    if query not in results:
        results[query] = fib(query)

with open("fibocnt.out", "w") as f:
    for query in queries:
        f.write(str(results[query]) + "\n")
