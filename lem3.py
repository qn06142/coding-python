import sys
import itertools

def tsp_dp(cost):
    n = len(cost)

    dp = [[float('inf')] * n for _ in range(1 << n)]

    for i in range(n):
        dp[1 << i][i] = 0

    for mask in range(1 << n):
        for i in range(n):
            if mask & (1 << i):  
                for j in range(n):
                    if not (mask & (1 << j)):  
                        next_mask = mask | (1 << j)
                        dp[next_mask][j] = min(dp[next_mask][j], dp[mask][i] + cost[i][j])

    return min(dp[(1 << n) - 1][i] for i in range(n))

n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]

result = tsp_dp(cost)
print(result)