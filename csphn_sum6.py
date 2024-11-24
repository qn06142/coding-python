pref = [0]
for i in range(1, int(1e5 + 1)):
    pref.append(1 + (i - 1) % 9)
    pref[i] += pref[i - 1]
q = int(input())
for _ in range(0, q):
    a, b = tuple(int(i) for i in input().split())
    print(pref[b] - pref[a - 1])
