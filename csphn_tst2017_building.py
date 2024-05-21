n = int(input())
a = [(abs(int(i)), int(i) > 0) for i in input().split()]

a.sort()
dp = [1 for i in range(0, n + 5)]
prefmax0 = 0
prefmax1 = 0
j = 0
for i in range(1, n + 1):
    while j + 1 < i and a[j][0] < a[i - 1][0]:
        if a[j][1]:
            prefmax1 = max(prefmax1, dp[j + 1])
        else:
            prefmax0 = max(prefmax0, dp[j + 1])
        j += 1
    if a[i- 1][1]:
        dp[i] = prefmax0 + 1
    else:
        dp[i] = prefmax1 + 1
print(dp[n])