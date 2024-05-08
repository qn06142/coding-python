
def max_tower_height(n, bricks):

    bricks.sort()

    dp = [0]*n

    parent = [-1]*n
    for i in range(n):
        dp[i] = bricks[i][2]

    for i in range(1, n):
        for j in range(i):
            if bricks[i][0] >= bricks[j][1] and dp[i] < dp[j] + bricks[i][2]:
                dp[i] = dp[j] + bricks[i][2]
                parent[i] = j

    max_index = dp.index(max(dp))

    tower = []
    while max_index != -1:
        tower.append(bricks[max_index][3])
        max_index = parent[max_index]

    return max(dp), tower

n = int(input())
bricks = []
for i in range(n):
    ai, bi, hi = tuple(int(i) for i in input().split())
    bricks.append((ai, bi, hi, i + 1))
height, tower = max_tower_height(n, bricks)
print(height)
print(*tower)