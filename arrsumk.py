def max_subarray_sum(n, R, array):
    max_sum = float('-inf')

    for s in range(1, R + 1):

        current_sum = sum(array[:s])
        max_sum = max(max_sum, current_sum)

        for i in range(s, n):
            current_sum += array[i] - array[i - s]
            max_sum = max(max_sum, current_sum)

    return max_sum

n, R = map(int, input().split())
array = list(map(int, input().split()))

print(max_subarray_sum(n, R, array))