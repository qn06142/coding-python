def count_ways_to_add_commas(s):
    n = len(s)
    dp = [1] * (n + 1)
    for i in range(1, n + 1):
        for j in range(i):
            if s[j:i] > s[j-1:j] if j > 0 else True:
                dp[i] += dp[j]
    return dp[-1]

s = input()
print(count_ways_to_add_commas(s))