def solve():
    import sys
    from collections import deque

    input = sys.stdin.readline
    n = int(input().strip())
    r1, c1 = map(int, input().split())
    r2, c2 = map(int, input().split())

    r1, c1, r2, c2 = r1 - 1, c1 - 1, r2 - 1, c2 - 1

    grid = [list(input().strip()) for _ in range(n)]

    def bfs(start_r, start_c):
        visited = [[False] * n for _ in range(n)]
        comp = []
        dq = deque()
        dq.append((start_r, start_c))
        visited[start_r][start_c] = True
        while dq:
            i, j = dq.popleft()
            comp.append((i, j))
            for di, dj in [(-1,0),(1,0),(0,-1),(0,1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < n and not visited[ni][nj] and grid[ni][nj] == '0':
                    visited[ni][nj] = True
                    dq.append((ni, nj))
        return comp, visited

    comp1, visited1 = bfs(r1, c1)

    if visited1[r2][c2]:
        print(0)
        return

    comp2, _ = bfs(r2, c2)

    min_cost = float('inf')
    for i, j in comp1:
        for k, l in comp2:
            cost = (i - k) ** 2 + (j - l) ** 2
            if cost < min_cost:
                min_cost = cost
    print(min_cost)

if __name__ == '__main__':
    solve()