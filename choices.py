#print('\n'.join(str(__import__('math').comb(*(int(i) for i in input().split()))% (10 ** 9 + 7))  for j in range(int(input()))))
import sys
MOD = 10**9 + 7
data = list(map(int, sys.stdin.buffer.read().split()))
t = data[0]
pairs = data[1:]
ns = pairs[0::2]
ks = pairs[1::2]

mx = max(ns) if ns else 0
fact = [1] * (mx + 1)
for i in range(1, mx + 1):
    fact[i] = fact[i - 1] * i % MOD

inv = [1] * (mx + 1)
if mx >= 0:
    inv[mx] = pow(fact[mx], MOD - 2, MOD)
    for i in range(mx, 0, -1):
        inv[i - 1] = inv[i] * i % MOD

out = []
for n, k in zip(ns, ks):
    if k < 0 or k > n:
        out.append("0")
    else:
        out.append(str(fact[n] * inv[k] % MOD * inv[n - k] % MOD))

sys.stdout.write("\n".join(out))
