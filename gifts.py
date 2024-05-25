n, k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
ans = 198910890128
for i in range(0, n - k):
    newa = a[:i] + a[i + k:]
    best = 0
    for i in range(0, n - 2 * k):
        sum_ = 0
        for j in range(0, k):
            sum_ += newa[i + j + 1]
        best = max(sum_, best)
        #print(sum_, i)
    #print(*newa)
    ans = min(ans, best)
print(ans)