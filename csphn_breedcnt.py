n, q = map(int, input().split())
a = [int(input()) for _ in range(n)]

pref1 = [0] * (n + 1)
pref2 = [0] * (n + 1)
pref3 = [0] * (n + 1)

for i in range(1, n + 1):
    pref1[i] = pref1[i - 1] + (1 if a[i - 1] == 1 else 0)
    pref2[i] = pref2[i - 1] + (1 if a[i - 1] == 2 else 0)
    pref3[i] = pref3[i - 1] + (1 if a[i - 1] == 3 else 0)

for _ in range(q):
    l, r = map(int, input().split())

    holsteins = pref1[r] - pref1[l - 1]
    guernseys = pref2[r] - pref2[l - 1]
    jerseys = pref3[r] - pref3[l - 1]
    print(holsteins, guernseys, jerseys)