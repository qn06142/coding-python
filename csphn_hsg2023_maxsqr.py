m, n, k = tuple(int(i) for i in input().split())

a = list(list(0 for i in range(0, n)) for i in range(0, m))
def largestKSubmatrix(a):
    dp = [[0 for x in range(n)]
             for y in range(m)]
 
    result = 0
    for i in range(n):
        for j in range(m):
             
            # If elements is at top 
            # m or first numn, 
            # it wont form a square
            # matrix's bottom-right
            if (i == 0 or j == 0):
                dp[i][j] = 1
 
            else:
                 
                # Check if adjacent 
                # elements are equal
                if (a[i][j] == a[i - 1][j] and
                    a[i][j] == a[i][j - 1] and
                    a[i][j] == a[i - 1][j - 1]):
                     
                    dp[i][j] = min(min(dp[i - 1][j], 
                                       dp[i][j - 1]),
                                       dp[i - 1][j - 1] ) + 1
 
                # If not equal, then  
                # it will form a 1x1
                # submatrix
                else:
                    dp[i][j] = 1
 
            # Update result at each (i,j)
            result = max(result, dp[i][j])
             
    return result
for i in range(0, k):
    t, l, b, r = tuple(int(i) - 1 for i in input().split())
    for i in range(t, b + 1):
        for j in range(l, r + 1):
            a[i][j] += 1
print(largestKSubmatrix(a))