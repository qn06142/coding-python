import sys
data = list(map(int, sys.stdin.read().split()))
n = data[0]
a = data[1:1+n]
pref = [1] * (n + 1)
for i in range(1, n + 1):
    pref[i] = pref[i - 1] * a[i - 1]
suf = [1] * (n + 2)
for i in range(n, 0, -1):
    suf[i] = suf[i + 1] * a[i - 1]
stor = {}
for i in range(1, n + 1):
    prod = pref[i - 1] * suf[i + 1]
    stor.setdefault(prod, set()).add(a[i - 1])
max_prod = max(stor.keys())
s = stor[max_prod]
print(min(s), max(s))