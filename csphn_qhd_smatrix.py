def count_special_matrices(n, m, k, matrix):

    dp = [[0] * (n + 1) for _ in range(n + 1)]
    column_sum = [0] * n

    for i in range(m):
        for j in range(n):
            column_sum[j] += matrix[i][j]

    cnt0 = column_sum.count(0)
    cnt1 = column_sum.count(1)

    dp[cnt0][cnt1] = 1

    for i in range(cnt0, -1, -1):
        for j in range(cnt1, -1, -1):
            current_ways = dp[i][j]
            if current_ways == 0:
                continue

            if i >= 2:
                dp[i-2][j+2] += current_ways * i * (i-1) // 2

            if i >= 1 and j >= 1:
                dp[i-1][j] += current_ways * i * j

            if j >= 2:
                dp[i][j-2] += current_ways * j * (j-1) // 2

    result = dp[0][0] % k
    return result

n, m, k = tuple(int(i) for i in input().split())
matrix = [list(int(i) for i in input()) for i in range(0, m)]

print(count_special_matrices(n, m, k, matrix))  