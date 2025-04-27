def longest_increasing_path(matrix):
    n = len(matrix)
    m = len(matrix[0]) if n > 0 else 0

    dp = [[1] * m for _ in range(n)]

    cells = []
    for i in range(n):
        for j in range(m):
            cells.append((matrix[i][j], i, j))

    cells.sort()

    for value, i, j in cells:
        for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            ni, nj = i + di, j + dj
            if 0 <= ni < n and 0 <= nj < m and matrix[ni][nj] > value:
                dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1)

    return max(max(row) for row in dp)

if __name__ == '__main__':
    import sys
    data = sys.stdin.read().split()
    if not data:
        exit(0)

    n = int(data[0])
    m = int(data[1])
    matrix = []
    index = 2
    for i in range(n):
        row = []
        for j in range(m):
            row.append(int(data[index]))
            index += 1
        matrix.append(row)

    print(longest_increasing_path(matrix))