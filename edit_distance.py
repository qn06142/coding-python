a = input()
b = input()
na = len(a)
nb = len(b)
dp = [[1e9 for _ in range(nb+1)] for _ in range(na+1)]
dp[0][0] = 0
for i in range(na+1):
    for j in range(nb+1):
        if i:
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
        if j:
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1)
        if i and j:
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]))
print(dp[na][nb])
