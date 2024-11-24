n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
s = a[0]
if m == 1:
    print(0)
elif n == 1 and s < m:
    print(-1)
elif s >= m:
    print(1)
else:
    for i in range(1, n):
        s += a[i] - 1
        if s >= m:
            print(i + 1)
            break
        elif s < m and i == n - 1:
            print(-1)
