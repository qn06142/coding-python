def factorial(n):
    return facts[n]

def combination(n, k, p):
    if k > n:
        return 0
    numerator = facts[n]
    denominator = (facts[k] * facts[n - k]) % p
    return (numerator * pow(denominator, p - 2, p)) % p

t, p = map(int, input().split())
facts = [1] * (10 ** 5)

for i in range(2, 10 ** 5):
    facts[i] = facts[i - 1] * i % p

for _ in range(t):
    n, k = map(int, input().split())
    print(combination(n, k, p))
