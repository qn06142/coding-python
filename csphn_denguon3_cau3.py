def min_cost(n, c, h):
    hmax = max(h)
    F = [[0 for _ in range(hmax+1)] for _ in range(n+1)]
    Low = [[1e18 for _ in range(hmax+1)] for _ in range(n+1)]
    High = [[1e18 for _ in range(hmax+1)] for _ in range(n+1)]

    for i in range(1, n+1):
        Low[i-1][0] = F[i-1][0] - c * 0
        for x in range(1, hmax+1):
            Low[i-1][x] = min(Low[i-1][x-1], F[i-1][x] - c * x)

        High[i-1][hmax] = F[i-1][hmax] + c * hmax
        for x in range(hmax-1, -1, -1):
            High[i-1][x] = min(High[i-1][x+1], F[i-1][x] + c * x)

        for x in range(hmax+1):
            F[i][x] = min(Low[i-1][x] + c * x, High[i-1][x] - c * x) + (x - h[i-1]) ** 2

    return min(F[n])
n, c = (int(i) for i in input().split())
h = [int(input()) for i in range(0, n)]
print(min_cost(n, c, h))
