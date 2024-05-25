def find_digit(a, b, n):

    remainder = a % b
    cycle = []
    seen = {}
    while remainder not in seen:
        seen[remainder] = len(cycle)
        cycle.append((remainder * 10) // b)

    cycle_length = len(cycle) - seen[remainder]

    if n < len(cycle):
        return cycle[n]
    else:
        return cycle[seen[remainder] + (n - seen[remainder]) % cycle_length]

a = int(input())
b = int(input())
n = int(input())
print(find_digit(a, b, n))
