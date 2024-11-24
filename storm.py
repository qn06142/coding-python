def count_unaffected_cells(n, r):

    unaffected_cells = n ** 2
    for i in range(n):
        for j in range(n):
            for x in range(n):
                for y in range(n):
                    if abs(x - i) + abs(y - j) <= r[i][j] and r[i][j] != 0:
                        unaffected_cells -= 1

    return unaffected_cells

n = int(input())
r = [[int(x) for x in input().split()] for _ in range(n)]

unaffected_cells = count_unaffected_cells(n, r)

print(unaffected_cells)
