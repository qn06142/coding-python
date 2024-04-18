import sys
from operator import itemgetter

def solve():
    n = int(input().strip())
    bricks = []
    for i in range(n):
        a, b, h = map(int, input().strip().split())
        bricks.append((a, b, h, i + 1))
    bricks.sort(key=itemgetter(0), reverse=True)
    dp = [0] * (n + 1)
    trace = [i for i in range(n + 1)]
    for i in range(n):
        j = i
        while j >= 0:
            if bricks[i][1] <= bricks[j][0] and dp[i + 1] < dp[j] + bricks[i][2]:
                dp[i + 1] = dp[j] + bricks[i][2]
                trace[i + 1] = j
            j -= 1
    idx = dp.index(max(dp))
    height = dp[idx]
    count = 0
    indices = []
    while idx > 0:
        count += 1
        indices.append(bricks[idx - 1][3])
        idx = trace[idx]
    print(height, count)
    print(' '.join(map(str, indices[::-1])))

solve()
print("hello")