def xor_queries(n, q, arr, queries):

    prefix_xor = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_xor[i] = prefix_xor[i - 1] ^ arr[i - 1]

    result = []
    for a, b in queries:
        xor_sum = prefix_xor[b] ^ prefix_xor[a - 1]
        result.append(xor_sum)

    return result

n, q = map(int, input().split())
arr = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(q)]

results = xor_queries(n, q, arr, queries)

for res in results:
    print(res)