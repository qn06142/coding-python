
s, n = input().strip().split()
n = int(n)
len_s = len(s)
dp = [(0, 0)] * (len_s + 5)
dp[len_s] = (-1, n)
for i in range(len_s - 1, -1, -1):
    if s[i] == '0':
        dp[i] = (1 + dp[i+1][0], 0)
    else:
        dp[i] = (1e18, 0) #type: ignore
        temp = 0
        for j in range(i, min(i + 20, len_s)):
            temp *= 10
            temp += int(s[j])
            if temp <= dp[j + 1][1]:
                if dp[i][0]>1+dp[j + 1][0]:
                    dp[i]=(1 + dp[j+1][0], temp)
                elif dp[i][0] == 1 + dp[j + 1][0]:
                    dp[i] = (1 + dp[j + 1][0], max(temp, dp[i][1]))
if dp[0][0] < 1e18:
    print(dp[0][0])
else:
    print("NO WAY")
