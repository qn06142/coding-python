m, n = tuple(int(i) for i in input().split())
x, y = tuple(int(i)-1 for i in input().split())
maze = [[int(i) for i in input().split()] for i in range(0, m)]
from collections import deque
from collections import deque

def shortest_path(maze, start):
    rows, cols = len(maze), len(maze[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
    queue = deque([(start, 0)])
    visited = set([start])

    while queue:
        (x, y), step = queue.popleft()

        # Check if current position is on the edge
        if x == 0 or y == 0 or x == rows - 1 or y == cols - 1:
            return step + 1  # Add 1 to include the edge step

        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 0 and (nx, ny) not in visited:
                queue.append(((nx, ny), step + 1))
                visited.add((nx, ny))

    return -1  # Return -1 if no path to the edge exists


start = (x, y)
print(shortest_path(maze, start))  # Output: 2
