from multiprocessing import Pool
import tqdm

def bits_to_matrix(num):

    if not (0 <= num < 65536):
        raise ValueError("Input must be a 16-bit unsigned integer.")

    binary_str = format(num, '016b')

    matrix = [['' for _ in range(4)] for _ in range(4)]

    for i in range(4):
        for j in range(4):
            bit_index = i * 4 + j
            if binary_str[bit_index] == '1':
                matrix[i][j] = 'H'
            else:
                matrix[i][j] = 'T'

    return matrix

def flip(grid, x, y):

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    grid[x][y] = 'H' if grid[x][y] == 'T' else 'T'
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < 4 and 0 <= ny < 4:
            grid[nx][ny] = 'H' if grid[nx][ny] == 'T' else 'T'
    return grid

def is_uniform(grid):

    first = grid[0][0]
    for row in grid:
        for cell in row:
            if cell != first:
                return False
    return True

def min_flips_to_uniform(initial_grid):
    min_flips = float('inf')
    for mask in range(1 << 16):
        grid = [row[:] for row in initial_grid]  
        flips = 0
        for i in range(16):
            if mask & (1 << i):
                x, y = divmod(i, 4)
                grid = flip(grid, x, y)
                flips += 1
        if is_uniform(grid):
            min_flips = min(min_flips, flips)
    return min_flips if min_flips != float('inf') else -1

def tqdm_map(func, iterable):
    with Pool() as p:
        for result in tqdm.tqdm(p.imap(func, iterable), total=len(iterable)):
            yield result

def process_matrix(num):
    matrix = bits_to_matrix(num)
    result = min_flips_to_uniform(matrix)
    return (num, result)

ans = list(tqdm_map(process_matrix, range(0, 2 ** 16)))

with open("csphn_flipans.out", "w") as f:
    for num, result in ans:
        f.write(f"{num} {result}\n")