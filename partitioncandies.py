def min_candy_difference(n, candies):
    # Tính prefix sums
    prefix_sums = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sums[i] = prefix_sums[i - 1] + candies[i - 1]
    
    total_candies = prefix_sums[n]
    min_difference = float('inf')
    
    # Kiểm tra tất cả các đoạn con
    for l in range(1, n + 1):
        for r in range(l, n + 1):
            sum_segment = prefix_sums[r] - prefix_sums[l - 1]
            difference = abs(total_candies - 2 * sum_segment)
            min_difference = min(min_difference, difference)
    
    return min_difference

n = int(input())
candies = list(map(int, input().split()))

result = min_candy_difference(n, candies)
print(result)
