MOD = 10**9 + 7
MAX = 10**6


fact = [1] * (MAX + 1)
ifact = [1] * (MAX + 1)


for i in range(2, MAX + 1):
    fact[i] = fact[i-1] * i % MOD


ifact[MAX] = pow(fact[MAX], MOD - 2, MOD)
for i in range(MAX - 1, 0, -1):
    ifact[i] = ifact[i+1] * (i+1) % MOD


def comb(x, y):
    if x < y or y < 0:
        return 0
    return fact[x] * ifact[y] % MOD * ifact[x-y] % MOD


import sys
input = sys.stdin.read
data = input().split()

T = int(data[0])
results = []

index = 1
for _ in range(T):
    m, n = map(int, data[index:index+2])
    index += 2
    
    results.append(comb(m - n + 1, n))


sys.stdout.write("\n".join(map(str, results)) + "\n")
