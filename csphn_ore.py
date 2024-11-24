def max_ore_value(m, n, gold_values, silver_values):
    gold = [[0] * n for _ in range(m)]
    silver = [[0] * n for _ in range(m)]

    # Initialize the values for the last column and last row
    for i in range(m):
        gold[i][n-1] = gold_values[i][n-1]
    for j in range(n):
        silver[m-1][j] = silver_values[m-1][j]

    # Update the values for the remaining cells
    for i in range(m):
        for j in range(n-2, -1, -1):
            gold[i][j] = gold_values[i][j] + gold[i][j+1]
    for j in range(n):
        for i in range(m-2, -1, -1):
            silver[i][j] = silver_values[i][j] + silver[i+1][j]

    # Calculate the optimal value
    max_value = 0
    for i in range(m):
        for j in range(n):
            max_value = max(max_value, gold[i][j] + silver[i][j])

    return max_value

import sys
input = sys.stdin.read
data = input().split()

# Read the input values
m = int(data[0])
n = int(data[1])
gold_values = []
silver_values = []

index = 2
for i in range(m):
    gold_values.append(list(map(int, data[index:index + n])))
    index += n

for i in range(m):
    silver_values.append(list(map(int, data[index:index + n])))
    index += n

# Calculate the result
result = max_ore_value(m, n, gold_values, silver_values)

# Print the result
print(result)
