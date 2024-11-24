prevsum = dict()
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
ans = 0
currsum = 0
for i in range(0, n):
    currsum += a[i]

    if currsum == k:
        ans += 1
    try:
        prevsum[currsum - k]
    except:
        pass
    else:
        ans += prevsum[currsum - k]
    try:
        prevsum[currsum] += 1
    except:
        prevsum[currsum] = 1

print(ans)
