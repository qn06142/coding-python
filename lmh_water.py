import heapq

def solve():
    m, n = map(int, input().split())

    heights = []
    for _ in range(m):
        row = list(map(int, input().split()))
        heights.append(row)
    if m <= 2 or n <= 2:
        print(0)
        return

    pq = []

    visited = [[False for _ in range(n)] for _ in range(m)]

    for i in range(m):
        for j in range(n):
            if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                heapq.heappush(pq, (heights[i][j], i, j))
                visited[i][j] = True

    ans = 0

    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    while pq:

        height, r, c = heapq.heappop(pq)

        for dr, dc in directions:
            nr, nc = r + dr, c + dc

            if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                visited[nr][nc] = True

                neigh = heights[nr][nc]

                if height > neigh:
                    ans += height - neigh

                new = max(height, neigh)
                heapq.heappush(pq, (new, nr, nc))

    print(ans)

solve()