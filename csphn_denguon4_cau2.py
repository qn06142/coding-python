def max_avg_rectangle(matrix, h, w, m, n):
    prefix_sum = [[0]*(n+1) for _ in range(m+1)]
    
    # Calculate prefix sum
    for i in range(m):
        for j in range(n):
            prefix_sum[i+1][j+1] = matrix[i][j] + prefix_sum[i+1][j] + prefix_sum[i][j+1] - prefix_sum[i][j]
    
    max_avg = float('-inf')
    max_rect = None
    
    # Find rectangle with max average
    for i in range(h, m+1):
        for j in range(w, n+1):
            cur_sum = prefix_sum[i][j] - prefix_sum[i-h][j] - prefix_sum[i][j-w] + prefix_sum[i-h][j-w]
            cur_avg = cur_sum / (h*w)
            
            if cur_avg > max_avg:
                max_avg = cur_avg
                max_rect = ((i-h, j-w), (i-1, j-1))
    
    return max_avg
m, n, h, w = tuple(int(i) for i in input().split())
matrix = tuple(tuple(int(i) for i in input().split()) for _ in range(0, m))
print(f'{max_avg_rectangle(matrix, h, w, m, n):.2f}')