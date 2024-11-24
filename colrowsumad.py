m, n = tuple(int(i) for i in input().split())

mat = [list(map(int, input().split())) for _ in range(m)]

colpre = [0]*n
rowpre = [0]*m

for i in range(m):
    for j in range(n):
        rowpre[i] += mat[i][j]
        colpre[j] += mat[i][j]

q = int(input())

for _ in range(q):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    print(rowpre[u] + colpre[v] - mat[u][v])
