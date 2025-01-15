n = int(input())
a = [0] + list(map(int, input()))
pref = [0 for i in range(0, n + 1)]
for i in range(1, n + 1):
    pref[i] = (pref[i - 1] * 10 + a[i])
import collections
cnt = collections.defaultdict(int)
cnt[0] = 1
ans = 0
for i in range(1, n + 1):
    for j in range(0, i):
        if((((pref[i] - pref[j]) // pow(10, i - j)) % 2023) == 0):
            print(((pref[i] - pref[j]) // pow(10, i - j)))
            print(i, j)
            ans += 1
print(ans)