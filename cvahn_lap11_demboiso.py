def divisible_numbers(n, k, m):
    return len([i for i in range(1, n+1) if i % k == 0 or i % m == 0])

# Read the input file
with open('Demboi.inp', 'r') as f:
    k, m, n = map(int, f.readline().split())

# Calculate the result
result = divisible_numbers(n, k, m)

# Write the result to the output file
with open('Demboi.out', 'w') as f:
    f.write(str(len(result)))
