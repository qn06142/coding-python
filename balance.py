def count_ways(n, M, weights):
    # Total number of possible ways to distribute weights
    total_ways = 3 ** n
    count = 0

    # Iterate through all possible configurations
    for i in range(total_ways):
        sum_A = 0
        sum_B = 0

        # Check each bit in the current configuration
        for j in range(n):
            # Determine where the weight j goes in the current configuration
            if (i // (3 ** j)) % 3 == 1:
                sum_B += weights[j]
            elif (i // (3 ** j)) % 3 == 2:
                sum_A += weights[j]

        # Check if the current configuration satisfies the condition
        if sum_A - sum_B == -M:
            count += 1

    return count

# Read input
import sys
input = sys.stdin.read
data = input().split()
n = int(data[0])
M = int(data[1])
weights = list(map(int, data[2:]))

# Calculate and output the result
print(count_ways(n, M, weights))
