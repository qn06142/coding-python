def min_subarray_length(n, S, a):
    left = 0
    current_sum = 0
    min_length = n + 1

    for right in range(n):
        current_sum += a[right]

        while current_sum >= S:
            min_length = min(min_length, right - left + 1)
            current_sum -= a[left]
            left += 1

    return min_length if min_length <= n else 0

n, S = map(int, input().split())
a = list(map(int, input().split()))

result = min_subarray_length(n, S, a)
print(result)