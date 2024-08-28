def max_elements_with_avg_less_than_k(N, A, Q, queries):

    A.sort()

    prefix_sum = [0] * (N + 1)
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1]

    results = []
    for K in queries:

        left, right = 0, N
        while left < right:
            mid = (left + right + 1) // 2
            if prefix_sum[mid] < K * mid:
                left = mid
            else:
                right = mid - 1
        results.append(left)

    return results

N = int(input())
A = list(map(int, input().split()))
Q = int(input())
queries = [int(input()) for _ in range(Q)]

results = max_elements_with_avg_less_than_k(N, A, Q, queries)
for result in results:
    print(result)