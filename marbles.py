import bisect

def solve(N, M, U, V, R, X, Y):
    # Sort the coordinates
    X.sort()
    Y.sort()

    outside_x = bisect.bisect_left(X, U - R) + N - bisect.bisect_right(X, U + R)
    outside_y = bisect.bisect_left(Y, V - R) + M - bisect.bisect_right(Y, V + R)

    total_beads = N * M

    inside = total_beads - outside_x * M - outside_y * N + outside_x * outside_y

    diff = abs(inside - (total_beads - inside))

    return diff

M, N, U, V, R = tuple(int(i) for i in input().split())
X = list(int(i) for i in input().split())
Y = list(int(i) for i in input().split())
print(solve(N, M, U, V, R, X, Y))
