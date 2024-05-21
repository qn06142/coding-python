def meet_in_the_middle(n, values):
    total_value = sum(values)
    target_value = total_value // 2
    mid = n // 2

    subset_values = {}
    for i in range(1 << mid):
        subset_value = sum(values[j] for j in range(mid) if (i & (1 << j)))
        subset_values[subset_value] = subset_values.get(subset_value, 0) + 1

    max_value = 0
    for i in range(1 << (n - mid)):
        subset_value = sum(values[mid + j] for j in range(n - mid) if (i & (1 << j)))
        if target_value - subset_value in subset_values:
            max_value = max(max_value, subset_value)

    return total_value - 2 * max_value
def brute_force(n, values):
    n = len(values)
    total_sum = sum(values)
    half_sum = total_sum // 2

    closest_value = float('inf')
    for mask in range(1 << n):
        subset_sum = 0
        for i in range(n):
            if (mask >> i) & 1:
                subset_sum += values[i]
        closest_value = min(closest_value, abs(total_sum - 2 * subset_sum))

    return closest_value


from random import randint
arr  = [randint(1,10) for i in range(0, 4)]
n = len(arr)
while meet_in_the_middle(n, arr) == brute_force(n, arr):
    arr  = [randint(1, 10) for i in range(0, 4)]
    n = len(arr)
    print(n)
    print(*arr)
    continue
print("wrong ans:")
print(n)
print(*arr)
print(meet_in_the_middle(n, arr), brute_force(n, arr))
"""
from sys import stdin
for i in stdin:
    n = int(i)
    values = [int(i) for i in input().split()]
    print(meet_in_the_middle(n, values))
"""