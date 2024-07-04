def min_additional_phones(N, D, phones):
    # Initialize dp array with a large number
    dp = [float('inf')] * N
    dp[0] = 0  # The first phone rings initially

    for i in range(1, N):
        if phones[i] == 1:
            dp[i] = dp[i - 1]
        else:
            dp[i] = dp[i - 1] + 1
        
        for j in range(1, D + 1):
            if i - j >= 0:
                dp[i] = min(dp[i], dp[i - j] + (1 if phones[i] == 0 else 0))

    return dp[N - 1]

import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
D = int(data[1])
phones = list(map(int, data[2:2 + N]))

result = min_additional_phones(N, D, phones)
print(result)