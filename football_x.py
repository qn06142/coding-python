def max_strength(n, m, k, a, b):
    dp = [[-float('inf')] * (m + 1) for _ in range(k + 1)]
    dp[0][0] = 0

    for i in range(1, n + 1):
        for x in range(k, 0, -1):
            for y in range(m, 0, -1):
                dp[x][y] = max(dp[x][y], dp[x][y - 1])

                for j in range(1, m + 1):
                    dp[x][y] = max(dp[x][y], dp[x - 1][y - 1] + a[i - 1] + b[i - 1][j - 1])

                dp[x][y] = max(dp[x][y], dp[x - 1][y] + a[i - 1])

    return max(dp[k])
n, m, k = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
b = list(list(int(i) for i in input().split()) for i in range(0, n))
print(max_strength(n, m, k, a, b))