import heapq

N = 105
inf = 1e9
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

n, m = map(int, input().split())
a = [[0]*N for _ in range(N)]
F = [[inf]*N for _ in range(N)]

for i in range(1, n+1):
    a[i] = [0] + list(map(int, input().split())) + [0]

for i in range(1, m+1):
    F[1][i] = a[1][i]
    F[n][i] = a[n][i]

for i in range(1, n+1):
    F[i][1] = a[i][1]
    F[i][m] = a[i][m]

st = []
for i in range(1, n+1):
    for j in range(1, m+1):
        heapq.heappush(st, (F[i][j], i, j))

while st:
    c, x, y = heapq.heappop(st)
    if c > F[x][y]:
        continue
    for k in range(4):
        i, j = x + dx[k], y + dy[k]
        if 1 <= i <= n and 1 <= j <= m:
            temp = max(F[x][y], a[i][j])
            if F[i][j] > temp:
                F[i][j] = temp
                heapq.heappush(st, (F[i][j], i, j))

ans = sum(F[i][j] - a[i][j] for i in range(1, n+1) for j in range(1, m+1))
print(ans)