n = int(input())
dp = []
dp.append(list(map(int, input().split())))

for i in range(1, n):
    a, b, c = map(int, input().split())
    dp.append([a + max(dp[i - 1][1], dp[i - 1][2]),
                b + max(dp[i - 1][2], dp[i - 1][0]),
                c + max(dp[i - 1][0], dp[i - 1][1])])

n -= 1
print(max(dp[n][0], max(dp[n][1], dp[n][2])))
