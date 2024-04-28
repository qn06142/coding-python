n, k = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]

dp = [0] * (k + 1)

for i in range(1, k + 1):
    for j in a:
        if(i >= j and not dp[i - j]):
            dp[i] = 1;
print("First" if dp[k] else "Second")