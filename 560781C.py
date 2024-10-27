MOD = int(1e9 + 7)

s = input()       
n = len(s)

dp = [0] * (n + 1)
dp[0] = 1  

last_occurrence = [-1] * 26  

for i in range(1, n + 1):
    char_idx = ord(s[i - 1]) - ord('a')  
    dp[i] = (2 * dp[i - 1]) % MOD  

    if last_occurrence[char_idx] != -1:
        dp[i] = (dp[i] - dp[last_occurrence[char_idx] - 1]) % MOD

    last_occurrence[char_idx] = i

result = (dp[n]) % MOD  

print(result)