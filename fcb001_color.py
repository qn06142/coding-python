def count_ways_to_color(N, K):
    MOD = 10**9 + 7

    if N == 1:
        return K % MOD

    dp = K % MOD

    for i in range(1, N):
        dp = (dp * (K - 1)) % MOD

    return dp

N, K = map(int, input().split())

result = count_ways_to_color(N, K)

print(result)