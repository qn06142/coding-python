def solve(matrix, h, w, m, n):
    pref = [[0]*(n+1) for _ in range(m+1)]
    
    for i in range(m):
        for j in range(n):
            pref[i+1][j+1] = matrix[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i][j]
    
    ans1 = float('-inf')
    ans = None
    
    for i in range(h, m+1):
        for j in range(w, n+1):
            cur_sum = pref[i][j] - pref[i-h][j] - pref[i][j-w] + pref[i-h][j-w]
            cur_avg = cur_sum / (h*w)
            
            if cur_avg > ans1:
                ans1 = cur_avg
                ans = ((i-h, j-w), (i-1, j-1))
    
    return ans1
m, n, h, w = tuple(int(i) for i in input().split())
matrix = tuple(tuple(int(i) for i in input().split()) for _ in range(0, m))
print(f'{solve(matrix, h, w, m, n):.2f}')