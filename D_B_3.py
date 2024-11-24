def max_average(N, K, A):
    def can_find_subarray_with_average_at_least(M):
        prefix_sum = 0
        min_prefix_sum = 0
        for i in range(N):
            prefix_sum += A[i] - M
            if i >= 1:
                min_prefix_sum = min(min_prefix_sum, prefix_sum - (A[i] - M))
            if prefix_sum - min_prefix_sum <= K:
                return True
        return False

    low, high = 0, max(A)
    precision = 1e-5
    ans = 0
    while high - low > precision:
        mid = (low + high) / 2
        if can_find_subarray_with_average_at_least(mid):
            low = mid + 1
            ans = mid
        else:
            high = mid - 1

    return int(low)

N, K = map(int, input().split())
A = list(map(int, input().split()))
print(max_average(N, K, A))