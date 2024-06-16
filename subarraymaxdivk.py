def max_dot_product(n, a, b):

    f = [[0] * (n + 1) for _ in range(n + 1)]
    g = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            f[i][j] = a[i-1] * b[j-1] + (f[i-1][j-1] if i > 1 and j > 1 else 0)
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            g[i][j] = min(f[i][j], g[i-1][j-1]);

    ans = float('-inf')
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            ans = max(ans, f[i][j] - g[i - 1][j - 1])

    return ans

n = int(input().strip())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))

result = max_dot_product(n, a, b)
print(result)