def min_groups(n, k, a):
    ans = 1
    lane = 0
    a.sort()
    for i in range(0, k):
        if a[i][0] <= lane:
            lane = min(lane, a[i][1])
        else:
            ans += 1
            lane = a[i][1]
    return ans

n, k = map(int, input().split())
pairs = [tuple(sorted(map(int, input().split()))) for _ in range(k)]

print(min_groups(n, k, pairs))
