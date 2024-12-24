from collections import deque

def solve_robot_gold():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    m, n, k = map(int, data[0].strip().split())

    grid = [list(map(int, data[i + 1].strip().split())) for i in range(m)]

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    result = [[0] * n for _ in range(m)]
    dp = [[grid[i][j] for j in range(n)] for i in range(m)]
    def bfs(x, y):
        max_gold = grid[x][y]
        visited = [[False] * n for _ in range(m)]
        visited[x][y] = True

        queue = deque([(x, y, 0)])

        while queue:
            cx, cy, steps = queue.popleft()

            if steps == k:
                continue

            for dx, dy in directions:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    max_gold = max(max_gold, grid[nx][ny])
                    queue.append((nx, ny, steps + 1))

        return max_gold

    for i in range(m):
        for j in range(n):
            result[i][j] = bfs(i, j)

    for row in result:
        print(' '.join(map(str, row)))
solve_robot_gold()