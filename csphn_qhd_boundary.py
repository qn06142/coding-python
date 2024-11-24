n = int(input())
a = []
b = []
dp = [[0 for i in range(2)] for i in range(n)]
for i in range (n):
    tmpa,tmpb = [int(i) for i in input().split()]
    a.append(tmpa)
    b.append(tmpb)
for i in range (n):
    if i==0:
        dp[i][0] = a[i]
        dp[i][1] = b[i]
    else:
        dp[i][0] = max(abs(b[i]-b[i-1])+a[i]+dp[i-1][0], abs(b[i]-a[i-1])+a[i]+dp[i-1][1])
        dp[i][1] = max(abs(a[i]-b[i-1])+b[i]+dp[i-1][0], abs(a[i]-a[i-1])+b[i]+dp[i-1][1])
print(max(dp[n-1][0],dp[n-1][1]))
