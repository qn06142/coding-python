def knapSack(W, wt, val, n): 
      
    # Initialize two rows for the dynamic programming table 
    dp = [[0 for i in range(W+1)] for j in range(2)] 
  
    # Binary flag for switching between the two rows 
    flag = 0
  
    # Build table dp[][] in bottom-up manner 
    for i in range(1, n+1): 
        # Switch between the two rows 
        flag = 1 - flag 
        for w in range(1, W+1): 
            if wt[i-1] <= w: 
                dp[flag][w] = max(dp[1-flag][w], val[i-1] + dp[1-flag][w-wt[i-1]]) 
            else: 
                dp[flag][w] = dp[1-flag][w] 
      
    # Return the maximum value of knapsack 
    return dp[flag][W] 

  

n, w = tuple(int(i) for i in input().split())
weight = tuple(int(i) for i in input().split())
profit = tuple(int(i) for i in input().split())
print(knapSack(w, weight, profit, n)) 