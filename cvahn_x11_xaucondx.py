with open("XAUCONDX.INP", "r") as f:
	f.readline()
	s = f.readline()
dp = [[0 for i in range (len(s))] for i in range (len(s))]
mx = 0
for i in range (len(s)-1,-1,-1):
    for j in range(i,len(s)):
        if i==j:
            dp[i][j] = 1
        elif i==j-1:
            if s[i]==s[j]:
                dp[i][j] = 2
            else:
                dp[i][j] = 0
        else:
            if s[i]==s[j]:
                if dp[i+1][j-1]>0:
                    dp[i][j] = dp[i+1][j-1]+2
                else:
                    dp[i][j] = 0
        mx = max(mx,dp[i][j])
with open("XAUCONDX.OUT", "w") as f:
	f.write(str(mx))