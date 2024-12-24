def max_gifts_delivered(T, N, small_times, M, large_times):

    def compute_dp(times, T):
        dp = [0] * (T + 1)
        for time in times:
            for t in range(T, time - 1, -1):
                dp[t] = max(dp[t], dp[t - time] + 1)
        return dp

    dp_small = compute_dp(small_times, T)

    dp_large = compute_dp(small_times + large_times, T)

    max_gifts = 0
    for t in range(T + 1):
        max_gifts = max(max_gifts, dp_small[t] + dp_large[T - t])

    return max_gifts

import sys
input = sys.stdin.read
data = input().split()

T = int(data[0])
N = int(data[1])
small_times = list(map(int, data[2:2 + N]))
M = int(data[2 + N])
large_times = list(map(int, data[3 + N:3 + N + M]))

result = max_gifts_delivered(T, N, small_times, M, large_times)

print(result)