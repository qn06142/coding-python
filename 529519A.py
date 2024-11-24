def count_subrectangles(n, m):
    MOD = 10**9 + 7

    subrectangles_n = n * (n + 1) // 2
    subrectangles_m = m * (m + 1) // 2

    result = (subrectangles_n * subrectangles_m) % MOD

    return result
n, m = tuple(int(i) for i in input().split())
print(count_subrectangles(n, m))