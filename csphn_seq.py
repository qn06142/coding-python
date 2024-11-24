def max_subarray_sum(n, k, arr):
    prefix_sum = [0] * (n + 1)
    prefix_min = [0] * (n + 1)
    max_sum = float('-inf')

    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]
        if i >= k:
            prefix_min[i - k] = min(prefix_min[i - k - 1], prefix_sum[i - k])
            max_sum = max(max_sum, prefix_sum[i] - prefix_min[i - k])

    return max_sum

n, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]

max_sum = max_subarray_sum(n, k, arr)

print(max_sum)
