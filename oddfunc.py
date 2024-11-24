MOD = 10**9 + 7

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def lcm(x, y):
    return x // gcd(x, y) * y

def solve(t, test_cases):
    results = []
    for n in test_cases:
        G = 1
        ans = 0
        i = 1
        while G <= n:
            G = lcm(G, i)
            if G > n:
                break
            ans += n // G
            i += 1
        results.append((ans + n) % MOD)
    return results

import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
test_cases = [int(data[i]) for i in range(1, t + 1)]

results = solve(t, test_cases)

for result in results:
    print(result)