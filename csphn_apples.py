def calculate_initial_apples(n, m):
    if n <= 0 or m <= 0:  # Handle the case where n or m is invalid
        return -1
    
    a = [0] * (n + 1)
    a[0] = m

    sum_ = ((2**n) * n * m) / (2**n + (n - 2) * 2**(n-1) + 1)
    for i in range(1, n + 1):
        a[i] = m - sum_ * (1/2 - 1/(2**i))
    if sum(a[1:]) != sum_ or any(a[i] < 0 for i in range(0, n + 1)):
        return -1
    return tuple(int(i) for i in a[1:])

for _ in range(0, int(input())):
    n, m = tuple(int(i) for i in input().split())
    result = calculate_initial_apples(n, m)
    if result == -1:
        print(-1)
    else:
        print(*result)
