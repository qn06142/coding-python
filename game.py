def max_reward(t, datasets):
    results = []
    for data in datasets:
        n = data[0]
        a = data[1]
        
        if n == 1:
            results.append(0.0)
            continue
        
        # dp arrays
        dp = [[0, 0] for _ in range(n)]
        
        # Initialize dp for the first element
        dp[0][0] = 0
        dp[0][1] = 0
        
        for i in range(1, n):
            # If we do not delete the i-th element
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            
            # If we delete the i-th element
            if i == 1:
                dp[i][1] = a[i-1]  # Only one neighbor (a[0])
            elif i == n - 1:
                dp[i][1] = dp[i-1][0] + a[i-1]  # Only one neighbor (a[n-2])
            else:
                dp[i][1] = dp[i-1][0] + (a[i-1] + a[i+1]) / 2  # Two neighbors
                
        # The result is the maximum value we can get at the last element
        results.append(round(max(dp[n-1][0], dp[n-1][1]), 1))
    
    return results

# Reading input
t = int(input())
datasets = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    datasets.append((n, a))

# Getting results
results = max_reward(t, datasets)

# Printing results
for result in results:
    print(result)
