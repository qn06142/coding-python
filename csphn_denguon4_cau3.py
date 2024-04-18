def count_squares(x_coords, y_coords, n, m):

    squares = 0
    cnt = 0
    l = []
    r = []
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            cnt += 1
            l.append(abs(x_coords[i] - x_coords[j]))
    cnt = 0
    for i in range(0, m - 1):
        for j in range(i + 1, m):
            cnt += 1
            r.append(abs(y_coords[i] - y_coords[j]))
    from bisect import bisect_left, bisect_right
    r.sort()
    for i in l:
        tmp = bisect_left(r, i)
        if tmp != n and tmp != -1:
            squares += bisect_right(r, i) - tmp
    return squares

h, v = tuple(int(i) for i in input().split())
x_coords = [int(i) for i in input().split()]
y_coords = [int(i) for i in input().split()]
print(count_squares(x_coords, y_coords, h, v))
