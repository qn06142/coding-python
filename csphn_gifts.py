n, k = map(int, input().split())
a = list(map(int, input().split()))
s = [0]*(n+1)
L = [-10**18]*(n+1)
R = [-10**18]*(n+1)
for i in range(1, n+1):
    s[i] = s[i - 1] + a[i - 1]
for i in range(k, n+1):
    L[i] = max(L[i - 1], s[i] - s[i - k])
for i in range(n - k, 0, -1):
        R[i] = max(R[i + 1], s[i + k - 1] - s[i - 1])
res = 10**18
for i in range(k - 1, n - k + 1):
    res = min(res, max(L[i], R[i + k]))
print(res)
