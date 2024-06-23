def min_cost_to_buy(n, prices):

    prefix_sums = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sums[i] = prefix_sums[i - 1] + prices[i - 1]

    total_sum = prefix_sums[n]
    min_cost = float('inf')

    left = 0
    right = 1

    while right <= n:

        current_sum = prefix_sums[right] - prefix_sums[left]

        cost = abs(2 * current_sum - total_sum)
        min_cost = min(min_cost, cost)

        right += 1

        while left < right - 1 and 2 * current_sum > total_sum:
            left += 1
            current_sum = prefix_sums[right - 1] - prefix_sums[left]
            cost = abs(2 * current_sum - total_sum)
            min_cost = min(min_cost, cost)

    return min_cost

n = int(input())
prices = list(map(int, input().split()))
print(min_cost_to_buy(n, prices))
