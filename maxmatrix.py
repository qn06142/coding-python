m, n = tuple(int(i) for i in input().split())

matrix = tuple(tuple(int(i == '.') for i in input()) for i in range(0, n))

dp = [[0 for i in range(0, m)] for j in range(0, n)]

for i in range(0, n):
    dp[i][0] = matrix[i][0]
for i in range(0, m):
    dp[0][i] = matrix[0][i]

for i in range(1, n):
    for j in range(1, m):
        if matrix[i][j]:
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
        else:
            dp[i][j] = 0
maxdp = dp[0][0]
maxi = 0
maxj = 0
for i in range(1, n):
    for j in range(1, m):
        if maxdp < dp[i][j]:
            maxdp = dp[i][j]
            maxi = i
            maxj = j
print((maxi + maxj) * 2)
for i in dp:
    print(*i)