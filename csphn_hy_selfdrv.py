import sys
from typing import List, Tuple

maxk = 2005
maxn = 200010
mod = 1000000007

m, n, k = 0, 0, 0
a = [(0, 0) for _ in range(maxk)]
GT = [0 for _ in range(maxn+1)]
f = [0 for _ in range(maxk)]

def E_gcd(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return 1, 0
    x1, y1 = E_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return x, y

def combin(u: int, v: int) -> int:
    b = GT[u] * GT[v-u] % mod
    x, y = E_gcd(b, mod)
    x = (x + mod * mod) % mod
    return GT[v] * x % mod

def Chbi() -> None:
    GT[0] = 1
    for i in range(1, maxn+1):
        GT[i] = GT[i-1] * i % mod


m, n, k = map(int, sys.stdin.readline().split())
for i in range(1, k+1):
    u, v = map(int, sys.stdin.readline().split())
    a[i] = (u, v)
a.sort()
a[k+1] = (m, n)
Chbi()
f[1] = combin(a[1][0]-1, a[1][0]+a[1][1]-2)
for i in range(2, k+2):
    f[i] = combin(a[i][0]-1, a[i][0]+a[i][1]-2)
    for j in range(1, i):
        if a[j][1] <= a[i][1]:
            t = combin(a[i][0]-a[j][0], a[i][0]-a[j][0]+a[i][1]-a[j][1]) * f[j] % mod
            f[i] = (f[i] - t + mod * mod) % mod
print(f[k+1])
