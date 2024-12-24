def precompute(N):
    dp = [[0] * (N + 1) for _ in range(N + 1)]
    for i in range(N + 1):
        dp[i][0] = 1  
    for i in range(1, N + 1):
        for k in range(1, i + 1):
            dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1]
    return dp

def find_combination(N, K, S, dp):
    result = []
    current = 1
    for i in range(1, K + 1):
        for num in range(current, N + 1):
            if dp[N - num][K - i] >= S:
                result.append(num)
                current = num + 1
                break
            else:
                S -= dp[N - num][K - i]
    return result

def find_rank(N, K, B, dp):
    rank = 1
    current = 1
    for i in range(K):
        for num in range(current, B[i]):
            rank += dp[N - num][K - i - 1]
        current = B[i] + 1
    return rank

def main():
    N, K = map(int, input().split())
    dp = precompute(N)

    S = int(input())
    B = list(map(int, input().split()))

    combination = find_combination(N, K, S, dp)
    print(" ".join(map(str, combination)))

    print(find_rank(N, K, B, dp))

if __name__ == "__main__":
    main()