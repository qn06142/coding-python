n, m = map(int, input().split())

a = [input().strip() for _ in range(n)]

b = [input().strip() for _ in range(n)]

count = 0  
for i in range(m):

    black = {a[j][i] for j in range(n)}
    white = {b[j][i] for j in range(n)}

    if black.intersection(white) == set():
        count += 1

print(count)