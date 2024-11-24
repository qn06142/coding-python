def count_black_rectangles(grid, N):
    MOD = 10007

    # Initialize the 2D arrays
    ul = [[0] * (N + 1) for _ in range(N + 1)]
    ur = [[0] * (N + 1) for _ in range(N + 1)]
    dl = [[0] * (N + 1) for _ in range(N + 1)]
    dr = [[0] * (N + 1) for _ in range(N + 1)]

    # Calculate the values for the arrays
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            f = 1 if grid[i - 1][j - 1] == 'B' else 0
            ul[i][j] = ul[i][j - 1] + ul[i - 1][j] - ul[i - 1][j - 1] + f
            ur[i][N - j + 1] = ur[i][N - j + 2] + ur[i - 1][N - j + 1] - ur[i - 1][N - j + 2] + f
            dl[N - i + 1][j] = dl[N - i + 2][j] + dl[N - i + 1][j - 1] - dl[N - i + 2][j - 1] + f
            dr[N - i + 1][N - j + 1] = dr[N - i + 2][N - j + 1] + dr[N - i + 1][N - j + 2] - dr[N - i + 2][N - j + 2] + f

    # Count the number of distinct pairs of black rectangles
    count = 0
    for i in range(2, N + 1):
        for j in range(2, N + 1):
            count += (ul[i - 1][j - 1] * (dr[N][N] - dr[i][j]) + ur[i - 1][N - j + 1] * (dl[N][N] - dl[i][j])) % MOD

    return count % MOD
N = int(input())
matrix = tuple(tuple(input()) for i in range(0, N))
print(count_black_rectangles(matrix, N))