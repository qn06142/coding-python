def find_max_length_subarray(n, k, a):

    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1]

    max_length = 0

    sum_indices = {}
    for i in range(n + 1):
        target_sum = prefix_sum[i] - k * i
        if target_sum in sum_indices:
            length = i - sum_indices[target_sum]
            if length > max_length:
                max_length = length
        else:
            sum_indices[target_sum] = i

    return max_length

n, k = map(int, input().split())
a = list(map(int, input().split()))

result = find_max_length_subarray(n, k, a)

print(result)