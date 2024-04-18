def find_len(arr, n, m):
	# Define the maximum values for maxN and maxM
	maxN = 1000
	maxM = 1000

	# To store the states of DP
	dp = [[0 for _ in range(maxM)] for _ in range(n + 1)]

	# Base case
	for curr in range(m):
		if curr == 0:
			dp[n][curr] = 0
		else:
			dp[n][curr] = -1

	# Tabulation
	for i in range(n - 1, -1, -1):
		for curr in range(m):
			# Recurrence relation
			l = dp[i + 1][curr]
			r = dp[i + 1][(curr + arr[i]) % m]
			dp[i][curr] = l
			if r != -1:
				dp[i][curr] = max(dp[i][curr], r + 1)

	if dp[0][0] == -1:
		return 0
	else:
		return dp[0][0]

n, m = tuple(int(i) for i in input().split())
arr = [int(i) for i in input().split()]
# Function call
print(n - find_len(arr, n, m))
