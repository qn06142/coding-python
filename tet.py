def mod_exp(a, b, p):

    result = 1
    a = a % p
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % p
        a = (a * a) % p
        b //= 2
    return result

T = int(input())
for _ in range(T):
    m, n, p = map(int, input().split())

    if m - n + 1 < n:
        print(0)
        continue

    N = m - n + 1  
    num = 1

    for i in range(n):
        num = (num * ((N - i) % p)) % p

    den = 1
    for i in range(1, n+1):
        den = (den * i) % p

    inv_den = mod_exp(den, p-2, p)

    res = (num * inv_den) % p
    print(res)