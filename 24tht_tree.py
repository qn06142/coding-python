def generate_primes(n):
    # Tạo danh sách số nguyên tố sử dụng Sieve of Eratosthenes
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    p = 2
    while p * p <= n:
        if sieve[p]:
            for i in range(p * p, n + 1, p):
                sieve[i] = False
        p += 1
    primes = [i for i in range(n + 1) if sieve[i]]
    return primes

def spiral_order(matrix, cannot_plant):
    R, C = len(matrix), len(matrix[0])
    result = []
    seen = [[False] * C for _ in range(R)]
    dr = [0, 1, 0, -1]  # Directions: right, down, left, up
    dc = [1, 0, -1, 0]
    r = c = di = 0  # Starting point and direction index
    for _ in range(R * C):
        if (r, c) not in cannot_plant:
            result.append((r, c))
        seen[r][c] = True
        cr, cc = r + dr[di], c + dc[di]
        if 0 <= cr < R and 0 <= cc < C and not seen[cr][cc]:
            r, c = cr, cc
        else:
            di = (di + 1) % 4  # Change direction
            r, c = r + dr[di], c + dc[di]
    return result


# Input processing
N, M, K, Q = map(int, input().split())
cannot_plant = set()
for _ in range(K):
    x, y = map(int, input().split())
    cannot_plant.add((x - 1, y - 1))  # Convert to 0-indexed

primes = generate_primes(int(4e6))  # Generate enough primes
grid = [[0] * M for _ in range(N)]
spiral = spiral_order(grid, cannot_plant)
prime_index = 0
for r, c in spiral:
    if (r, c) not in cannot_plant:
        grid[r][c] = primes[prime_index]
        prime_index += 1
pref = [[0] * (M + 5) for _ in range(N + 5)]  # Prefix sum of grid values
for i in range(1, N + 1):
    for j in range(1, M + 1):
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i - 1][j - 1]

# Process each query
results = []
for _ in range(Q):
    x1, y1, x2, y2 = map(int, input().split())
    results.append(pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 -1] + pref[x1 - 1][y1 - 1])

# Output results
for result in results:
    print(result)