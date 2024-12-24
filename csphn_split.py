def max_segments(n, s):
    
    prefix = [0] * (n + 1)
    power10 = [1] * (n + 1)

    for i in range(1, n + 1):
        prefix[i] = (prefix[i - 1] * 10 + int(s[i - 1]))
        power10[i] = (power10[i - 1] * 10)

    
    dp = [0] * n
    last_value = [-1] * n  

    for i in range(n):
        for j in range(i + 1):
            
            length = i - j + 1
            segment_value = (prefix[i + 1] - prefix[j] * power10[length])

            
            if j == 0 or segment_value > last_value[j - 1]:
                dp[i] = max(dp[i], (dp[j - 1] if j > 0 else 0) + 1)
                last_value[i] = max(last_value[i], segment_value)

    return dp[n - 1]  +1


n = int(input())
s = input().strip()


print(max_segments(n, s))
