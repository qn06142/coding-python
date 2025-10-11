import sys

def next_pos(k, p):

    if ((k+1) & 1) == p:
        return k+1
    else:
        return k+2

data = sys.stdin.read().strip().split()
it = iter(data)

n = int(next(it))
A = [int(next(it)) for _ in range(n)]

m = int(next(it))
B = [int(next(it)) for _ in range(m)]

dp = [0] * (m + 1)

for j in range(m):
    dp[j+1] = next_pos(dp[j], B[j])

if n == 0:
    print(dp[m])

else:
    for i in range(1, n+1):
        new = [0] * (m + 1)

        new[0] = next_pos(dp[0], A[i-1])
        for j in range(1, m+1):

            opt1 = next_pos(dp[j], A[i-1])

            opt2 = next_pos(new[j-1], B[j-1])
            new[j] = opt1 if opt1 < opt2 else opt2
        dp = new

    print(dp[m])