from collections import defaultdict

MOD = 10**9 + 7

def count_sequences(a, q):
    n = len(a)
    count = [0] * n
    dp = [defaultdict(int) for _ in range(n)]

    for i in range(n):
        for j in range(i):
            if a[i] % a[j] == 0:
                r = a[i] // a[j]
                if r % q == 0:
                    dp[i][r] += dp[j][r // q]
                if r == q:
                    dp[i][r] += 1
        count[i] = dp[i][q]

    return count

# Read input
n, q = map(int, input().split())
a = list(map(int, input().split()))

# Calculate and print the result
result = count_sequences(a, q)
for i in range(1, n):
    print(result[i] % MOD, end=' ')
