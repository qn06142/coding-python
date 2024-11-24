from collections import defaultdict

def dfs(i, j, visited, grid):
    stack = [(i, j)]
    size = 0
    while stack:
        x, y = stack.pop()
        if (x, y) not in visited:
            visited.add((x, y))
            size += 1
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                    stack.append((nx, ny))
    return size

def count_slicks(grid):
    visited = set()
    sizes = defaultdict(int)
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1 and (i, j) not in visited:
                size = dfs(i, j, visited, grid)
                sizes[size] += 1
    return sizes

N, M = map(int, input().split())
grid = [list(map(int, input())) for _ in range(N)]
sizes = count_slicks(grid)
print(max(sizes))