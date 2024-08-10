MOD = 1000000007

def mod_pow(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def mod_inv(x, mod):

    return mod_pow(x, mod - 2, mod)

def geometric_sum(a, n):
    if a == 1:
        return n % MOD
    numerator = mod_pow(a, n + 1, MOD) - a
    if numerator < 0:
        numerator += MOD
    denominator = mod_inv(a - 1, MOD)
    return (numerator * denominator) % MOD

a, n = map(int, input().split())

result = geometric_sum(a, n)
print(result)