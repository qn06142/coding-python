def max_gift_value(n, a):
    # Initialize sum and w with zeros
    sum = [[0 for _ in range(n+1)] for _ in range(n+1)]
    w = [[0 for _ in range(n+1)] for _ in range(n+1)]
    
    # Calculate sum and w
    for i in range(1, n+1):
        for j in range(i, n+1):
            sum[i][j] = sum[i][j-1] + a[j]
            w[i][j] = w[i][j-1] + j*a[j]
    
    # Initialize max_value with negative infinity
    max_value = float('-inf')
    
    # Iterate over all pairs (i, j)
    for i in range(1, n+1):
        for j in range(i, n+1):
            # Calculate the value of the gift segment (i, j)
            value = w[i][j] - (i-1)*sum[i][j]
            
            # Update max_value if necessary
            max_value = max(max_value, value)
    
    # Return the maximum value
    return max_value
n = int(input())
array = [0] + [int(i) for i in input().split()]

max_value = max_gift_value(n, array)

print(max_value)
