# Importing necessary libraries
import sys
from collections import deque, defaultdict

# Reading input
input = sys.stdin.read
data = input().split()
m = int(data[0])
n = int(data[1])
c = int(data[2])

# Reading the map
map_data = []
idx = 3
for i in range(m):
    map_data.append([int(data[idx + j]) for j in range(n)])
    idx += n

# Direction vectors for moving up, down, left, right
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# Function to perform BFS and find all cells in a region
def bfs(start_i, start_j, region_id):
    queue = deque([(start_i, start_j)])
    regions[start_i][start_j] = region_id
    while queue:
        i, j = queue.popleft()
        for d in directions:
            ni, nj = i + d[0], j + d[1]
            if 0 <= ni < m and 0 <= nj < n and regions[ni][nj] == 0 and map_data[ni][nj] == map_data[start_i][start_j]:
                regions[ni][nj] = region_id
                queue.append((ni, nj))

# Identifying all regions
regions = [[0] * n for _ in range(m)]
region_id = 0
for i in range(m):
    for j in range(n):
        if regions[i][j] == 0:
            region_id += 1
            bfs(i, j, region_id)

# Building the adjacency list for the regions
adj_list = defaultdict(set)
for i in range(m):
    for j in range(n):
        for d in directions:
            ni, nj = i + d[0], j + d[1]
            if 0 <= ni < m and 0 <= nj < n and regions[i][j] != regions[ni][nj]:
                adj_list[regions[i][j]].add(regions[ni][nj])
                adj_list[regions[ni][nj]].add(regions[i][j])

# Performing graph coloring using greedy algorithm
color = {}
available_colors = set(range(1, c + 1))

def color_region(region):
    neighbor_colors = {color[neighbor] for neighbor in adj_list[region] if neighbor in color}
    for col in available_colors:
        if col not in neighbor_colors:
            return col

for region in range(1, region_id + 1):
    color[region] = color_region(region)

# Output the number of colors used
print(len(set(color.values())))

# Output the colored map
colored_map = [[color[regions[i][j]] for j in range(n)] for i in range(m)]
for row in colored_map:
    print(' '.join(map(str, row)))