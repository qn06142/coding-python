import heapq
import sys

def dijkstra(grid, start_row, start_col):
    R, C = len(grid), len(grid[0])
    dist = [[sys.maxsize] * C for _ in range(R)]
    dist[start_row][start_col] = grid[start_row][start_col]
    heap = [(grid[start_row][start_col], start_row, start_col)]
    
    while heap:
        current_dist, row, col = heapq.heappop(heap)
        
        if current_dist > dist[row][col]:
            continue
        
        for drow, dcol in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            new_row, new_col = row + drow, col + dcol
            if 0 <= new_row < R and 0 <= new_col < C:
                new_dist = current_dist + grid[new_row][new_col]
                if new_dist < dist[new_row][new_col]:
                    dist[new_row][new_col] = new_dist
                    heapq.heappush(heap, (new_dist, new_row, new_col))
        
        if col == 0 or col == C - 1:
            for new_col in [0, C - 1]:
                if new_col != col:
                    new_dist = current_dist + grid[row][new_col]
                    if new_dist < dist[row][new_col]:
                        dist[row][new_col] = new_dist
                        heapq.heappush(heap, (new_dist, row, new_col))
    
    return dist

def minimum_delivery_time(R, C, grid, deliveries):
    total_time = 0
    start_row, start_col = 0, 0
    
    for (A, B) in deliveries:
        A -= 1
        B -= 1
        dist = dijkstra(grid, start_row, start_col)
        total_time += dist[A][B]
        start_row, start_col = A, B
    
    return total_time

# Input reading
input = sys.stdin.read
data = input().split()
R = int(data[0])
C = int(data[1])
grid = []
index = 2
for _ in range(R):
    grid.append([int(data[i]) for i in range(index, index + C)])
    index += C
D = int(data[index])
index += 1
deliveries = []
for _ in range(D):
    A = int(data[index])
    B = int(data[index + 1])
    deliveries.append((A, B))
    index += 2

# Output result
print(minimum_delivery_time(R, C, grid, deliveries))