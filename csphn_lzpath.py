def trailing_zeros(x):
     return (x & -x).bit_length() - 1
n = int(input())
a = [[trailing_zeros(int(i)) for i in input().split()] for _ in range(0, n)]

dp = [[0]*n for _ in range(n)]
dp[0][0] = (a[0][0] == 0)

for i in range(1, n):
    dp[i][0] = dp[i-1][0] + (a[i][0] == 0)
    dp[0][i] = dp[0][i-1] + (a[0][i] == 0)

for i in range(1, n):
    for j in range(1, n):
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (a[i][j] == 0)

print(dp[-1][-1])