def max_score(N, K, a):

    dp = [0]*(N+1)

    for i in range(1, N+1):
        dp[i] = max(dp[max(0, i-K):i]) + a[i-1]

    return max(dp)

N, K = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
print(max_score(N, K, a))
