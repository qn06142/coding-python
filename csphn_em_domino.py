n = int(input())
mat = [[int(i) for i in input().split()] for i in range(0, n)]

for i in range(0, n):
    for j in range(0, n):
        for a in range(i, n):
            for b in range(j, n):
                smol = [[mat[x][y] for y in range(i, a)] for x in range(j, b)]
                