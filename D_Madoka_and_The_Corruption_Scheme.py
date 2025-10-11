fact = [1]
mod = int(1e9 + 7)
for i in range(1, 10 ** 5 + 5):
    fact.append(fact[i - 1] * i % mod)
n, k = (int(i) for i in input().split())
from sys import exit
if k >= n:
    print(2 ** n % mod)
    exit(0)
def comb(n, k):
    return fact[n] * pow(fact[k] * fact[n - k], -1, mod) % mod
print(sum(comb(n, i) for i in range(0, k + 1)) % mod)