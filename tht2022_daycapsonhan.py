MOD = 10**9 + 7
def count_subsequences(n, q, a):
    count = [0]*n
    dp = [0]*n
    if a[0] == 1:
        dp[0] = 1
    for i in range(1, n):
        dp[i] = dp[i-1]
        if a[i] % q == 0:
            j = a[i] // q
            if j < n:
                dp[i] += count[j]
                dp[i] %= MOD
        count[a[i]] += 1
    return dp

# Test the function
n, q = 5, 2
a = [1, 2, 8, 4, 2]
print(count_subsequences(n, q, a))
