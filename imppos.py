def count_important_positions(m, n, k, gifts):
    # Initialize DP tables and gifts table
    dp1 = [[0] * n for _ in range(m)]
    dp2 = [[0] * n for _ in range(m)]
    hasGift = [[0] * n for _ in range(m)]
    
    # Fill the gifts table
    for x, y in gifts:
        hasGift[x - 1][y - 1] = 1
    
    # Fill dp1 table (from (1,1) to (m,n))
    dp1[0][0] = hasGift[0][0]
    for i in range(1, m):
        dp1[i][0] = dp1[i - 1][0] + hasGift[i][0]
    for j in range(1, n):
        dp1[0][j] = dp1[0][j - 1] + hasGift[0][j]
    for i in range(1, m):
        for j in range(1, n):
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + hasGift[i][j]
    
    # Fill dp2 table (from (m,n) to (1,1))
    dp2[m - 1][n - 1] = hasGift[m - 1][n - 1]
    for i in range(m - 2, -1, -1):
        dp2[i][n - 1] = dp2[i + 1][n - 1] + hasGift[i][n - 1]
    for j in range(n - 2, -1, -1):
        dp2[m - 1][j] = dp2[m - 1][j + 1] + hasGift[m - 1][j]
    for i in range(m - 2, -1, -1):
        for j in range(n - 2, -1, -1):
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + hasGift[i][j]
    
    max_gifts = dp1[m - 1][n - 1]
    important_positions = 0
    
    # Check each gift position
    for x, y in gifts:
        x -= 1
        y -= 1
        if dp1[x][y] + dp2[x][y] - hasGift[x][y] == max_gifts:
            important_positions += 1
    
    return important_positions

# Example usage:
m, n, k = tuple(int(i) for i in input().split())
gifts = [tuple(int(i) for i in input().split()) for i in range(0, k)]
print(count_important_positions(m, n, k, gifts))  # Output the number of important positions