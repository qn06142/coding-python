with open("cau4.inp", "r") as f:
	m, n = tuple(int(i) for i in f.readline().split())
	d, r, h = tuple(int(i) for i in f.readline().split())
	a = [[int(i)-1 for i in f.readline().split()] for j in range(0, n)][:-1]
prefixsum = []
R = m
C = n
"""
def prefixSum2D(a) :
    global C, R
    psa = [[0 for x in range(C)] 
              for y in range(R)] 
    psa[0][0] = a[0][0]
 
    # Filling first row 
    # and first column
    for i in range(1, C) :
        psa[0][i] = (psa[0][i - 1] +
                       a[0][i])
    for i in range(0, R) :
        psa[i][0] = (psa[i - 1][0] +
                       a[i][0])
 
    # updating the values in 
    # the cells as per the 
    # general formula
    for i in range(1, R) :
        for j in range(1, C) :
 
            # values in the cells of 
            # new array are updated
            psa[i][j] = (psa[i - 1][j] +
                         psa[i][j - 1] -
                         psa[i - 1][j - 1] +
                           a[i][j])
    return psa
"""
def calculate_prefix_sum(matrix):
    rows, cols = len(matrix), len(matrix[0])
    prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
    
    for r in range(rows):
        for c in range(cols):
            prefix_sum[r+1][c+1] = matrix[r][c] + prefix_sum[r+1][c] + prefix_sum[r][c+1] - prefix_sum[r][c]
    
    return prefix_sum

prefixsum = calculate_prefix_sum(a)
def smallest_rectangle_sum(matrix, prefix_sum, d, h, i):
    min_sum = float('inf')
    rows, cols = len(matrix), len(matrix[0])
    
    for r1 in range(rows):
        for r2 in range(r1 + h - 1, rows):
            for c1 in range(cols):
                for c2 in range(c1 + d - 1, cols):
                    # Calculate the sum of the rectangle from (r1, c1) to (r2, c2)
                    total = prefix_sum[r2+1][c2+1] - prefix_sum[r1][c2+1] - prefix_sum[r2+1][c1] + prefix_sum[r1][c1]
                    
                    # Calculate the number of elements in the rectangle
                    num_elements = (r2 - r1 + 1) * (c2 - c1 + 1)
                    
                    # Calculate the difference between each element and i
                    diff = abs(total - i * num_elements)
                    
                    # Update the minimum sum
                    if diff < min_sum:
                        min_sum = diff
    
    return min_sum

print(smallest_rectangle_sum(a, prefixsum, r, d, h))