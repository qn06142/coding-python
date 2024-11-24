def max_students(n, m, l, a):

    a.sort()

    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = 0

    for j in range(1, m + 1):
        k = 0
        for i in range(1, n + 1):
            while k < i and a[i - 1] - a[k] > l:
                k += 1
            dp[i][j] = max(dp[i - 1][j], dp[k][j - 1] + (i - k))

    return max(dp[n])

n, m, l = map(int, input().strip().split())
a = list(map(int, input().strip().split()))

result = max_students(n, m, l, a)
print(result)