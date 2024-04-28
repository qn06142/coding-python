m, n, k = tuple(int(i) for i in input().split())

matrix = [[0 for _ in range(n)] for _ in range(m)]

def calcsquare(matrix):
    dp = [[0 for _ in range(n + 5)] for _ in range(m + 5)]

    for i in range(m):
        dp[i][0] = matrix[i][0]
    for i in range(n):
        dp[0][i] = matrix[0][i]

    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == matrix[i][j - 1] == matrix[i - 1][j] == matrix[i - 1][j - 1]:
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
            else:
                dp[i][j] = 0

    maxdp = max(max(row) for row in dp)
    return maxdp

for _ in range(k):
    t, l, b, r = tuple(int(i) - 1 for i in input().split())
    for i in range(t, b + 1):
        for j in range(l, r + 1):
            matrix[i][j] += 1
for i in matrix:
    print(*i)
print(calcsquare(matrix))