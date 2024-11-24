import cupy as cp
import tqdm

def bits_to_matrix(num):
    # Ensure the number is a 16-bit unsigned integer
    if not (0 <= num < 65536):
        raise ValueError("Input must be a 16-bit unsigned integer.")

    # Convert to binary and pad to ensure it is 16 bits
    binary_str = format(num, '016b')

    # Create the 4x4 matrix using CuPy
    matrix = cp.empty((4, 4), dtype=cp.str_)
    
    # Fill the matrix based on the binary string
    for i in range(4):
        for j in range(4):
            bit_index = i * 4 + j
            if binary_str[bit_index] == '1':
                matrix[i, j] = 'H'
            else:
                matrix[i, j] = 'T'

    return matrix

def flip(grid, x, y):
    # Flip the cell (x, y) and its neighbors
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    grid[x, y] = 'H' if grid[x, y] == 'T' else 'T'
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < 4 and 0 <= ny < 4:
            grid[nx, ny] = 'H' if grid[nx, ny] == 'T' else 'T'
    return grid

def is_uniform(grid):
    # Check if all coins are the same
    first = grid[0, 0]
    return cp.all(grid == first)

def min_flips_to_uniform(initial_grid):
    min_flips = float('inf')
    for mask in range(1 << 16):
        grid = initial_grid.copy()  # Create a copy of the grid
        flips = 0
        for i in range(16):
            if mask & (1 << i):
                x, y = divmod(i, 4)
                grid = flip(grid, x, y)
                flips += 1
        if is_uniform(grid):
            min_flips = min(min_flips, flips)
    return min_flips if min_flips != float('inf') else -1

# Calculate the answers with a progress bar
def process_matrix(num):
    matrix = bits_to_matrix(num)
    result = min_flips_to_uniform(matrix)
    return (num, result)

# Use tqdm for progress tracking in multiprocessing
def tqdm_map(func, iterable):
    for result in tqdm.tqdm(map(func, iterable), total=len(iterable)):
        yield result

# Calculate the answers with a progress bar for all 16-bit integers
ans = list(tqdm_map(process_matrix, range(0, 2 ** 16)))

# Prepare output for writing
with open("csphn_flipans.out", "w") as f:
    for num, result in ans:
        f.write(f"{num} {result}\n")
