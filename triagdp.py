n = int(input())
triag = [[int(i) for i in input().split()] for _ in range(0, n)]
grid = [[-1 for _ in range(0, n)] for _ in range(0, n)]
dp = [[-1 for _ in range(0, n + 1)] for _ in range(0, n + 1)]
for ind1, itm1 in enumerate(triag):
	for ind2, itm2 in enumerate(itm1):
		grid[ind1][ind2] = itm2
dp[1][1] = grid[0][0]
for i in range(1, n + 1):
	for j in range(1, n + 1):
		dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]) + grid[i-1][j-1]
print(dp[n][n])