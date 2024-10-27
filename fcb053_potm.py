n, q = map(int, input().split())
a = list(map(int, input().split()))

pref = [0] * (n + 1)
for i in range(1, n + 1):
    pref[i] = pref[i - 1] + a[i - 1]
for _ in range(q):
    t, x, k = map(int, input().split())
    if t == 0:
        print(pref[k])
    else:
        print(pref[x] - pref[x - k])