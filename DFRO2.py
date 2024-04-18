n, k = tuple(int(i) for i in input().split())
dp = [0] * (n + 5)
h = [0] + [int(i) for i in input().split()]
for i in range(2, n + 1):
	minallj = 1e9
	for j in range(1, k + 1):
		if i - j >= 1:
			minallj = min (minallj, dp[i - j] + abs(h[i] - h[i - j]))
	dp[i] = minallj
print(dp[n])