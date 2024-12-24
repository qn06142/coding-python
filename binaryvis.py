def generate_pattern(n, t):
    # Initialize the pattern as a list of lists
    pattern = [[0] * n for _ in range(t + 1)]
    pattern[0][0] = 1  # Initial condition: a single 1 at the start

    # Use the recurrence relation to compute each cell
    for i in range(1, t + 1):
        for j in range(n):
            pattern[i][j] = (
                pattern[i - 1][j] ^
                pattern[i - 1][(j - 1 + n) % n] ^
                pattern[i - 1][(j + 1) % n]
            )

    return pattern
def print_pattern(pattern):
    for row in pattern:
        print(''.join('█' if x == 1 else ' ' for x in row))


if __name__ == "__main__":
    n = 6  # Size of the array
    t = 100 # Number of time steps
    pattern = generate_pattern(n, t)
    print_pattern(pattern)
