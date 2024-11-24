n, m, k = (int(i) for i in input().split())
n += 2
m += 2
a = [[0 for i in range(0, m)] for _ in range(0, n)]
pref = [[0 for i in range(0, m)] for _ in range(0, n)]
n -= 2
m -= 2
for _ in range(0, k):
    i, j = (int(i) for i in input().split())
    a[i][j] = 1
for i in range(1, n + 1):
    for j in range(1, m + 1):
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j]
best = 0
for a in range(1, n + 1):
    for b in range(1, m + 1):
        j = m
        for i in range(a, n + 1):
            while j > b and pref[i][j] - pref[a - 1][j] - pref[i][b - 1] + pref[a - 1][b - 1] > 1:
                j -= 1
            if pref[i][j] - pref[a - 1][j] - pref[i][b - 1] + pref[a - 1][b - 1] == 1:
                best = max(best, (i - a + 1)*(j - b + 1))
print(best)