def calculate_initial_apples(n, m):
    # Initialize the array of apples each friend has
    a = [0] * (n + 1)
    a[0] = m

    # Calculate the total number of apples
    sum = m * (2**n) * n / (2**n + (n - 2) * 2**(n-1) + 1)

    # Calculate the initial number of apples each friend had
    for i in range(1, n + 1):
        a[i] = m - sum * (1/2 - 1/(2**i))

    return tuple(int(i) for i in a[1:])
for _ in range(0, int(input())):
    n, m = tuple(int(i) for i in input().split())
    print(*calculate_initial_apples(n, m))
