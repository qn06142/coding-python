def count_pairs(grid, x, y, d, m, n):
    pairs = 0
    for i in range(x-d, x+d+1):
        for j in range(y-abs(i-x), y+abs(i-x)+1):
            if i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == 1:
                if i+1 < m and grid[i+1][j] == 1:
                    pairs += 1
                if j+1 < n and grid[i][j+1] == 1:
                    pairs += 1
    return pairs

def largest_diamond(grid, k, m, n):
    max_d = 0
    for i in range(m):
        for j in range(n):
            d = 0
            while i-d >= 0 and i+d < m and j-d >= 0 and j+d < n and count_pairs(grid, i, j, d, m, n) <= k:
                max_d = max(max_d, d)
                d += 1
    return max_d

m, n, k = tuple(int(i) for i in input().split())
grid = [[int(i) for i in input().split()] for j in range(0, m)]
print(largest_diamond(grid, k, m, n))