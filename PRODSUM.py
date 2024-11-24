def max_weight(N, A):

    C_0 = sum((i + 1) * A[i] for i in range(N))

    max_C = C_0

    prefix_sum = [0] * (N + 1)
    suffix_sum = [0] * (N + 1)

    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1]

    for i in range(N - 1, -1, -1):
        suffix_sum[i] = suffix_sum[i + 1] + A[i]

    for i in range(N):
        new_C = C_0 + (1 - (i + 1)) * A[i] + prefix_sum[i]
        max_C = max(max_C, new_C)

    for i in range(N):
        new_C = C_0 + (N - (i + 1)) * A[i] - suffix_sum[i + 1]
        max_C = max(max_C, new_C)

    return max_C

N = int(input().strip())
A = list(map(int, input().strip().split()))

print(max_weight(N, A))