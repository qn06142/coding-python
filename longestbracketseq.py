def longest_regular_bracket_sequence(s):
    n = len(s)
    dp = [0] * n
    max_length = 0
    count = 0
    
    for i in range(1, n):
        if s[i] == ')':
            if s[i - 1] == '(':
                dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
            elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                dp[i] = dp[i - 1] + (dp[i - dp[i - 1] - 2] if i - dp[i - 1] >= 2 else 0) + 2
            max_length = max(max_length, dp[i])
    
    count = dp.count(max_length)
    
    if max_length == 0:
        return "0 1"
    else:
        return f"{max_length} {count}"

input_string = input()
print(longest_regular_bracket_sequence(input_string))
