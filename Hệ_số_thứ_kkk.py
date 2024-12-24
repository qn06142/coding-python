MOD = 2004511

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def mod_inv(x, mod):
    return mod_exp(x, mod - 2, mod)

def comb_mod_small(n, k, mod):
    if k > n:
        return 0
    numerator = 1
    denominator = 1
    for i in range(k):
        numerator = (numerator * (n - i)) % mod
        denominator = (denominator * (i + 1)) % mod
    return (numerator * mod_inv(denominator, mod)) % mod

def comb_mod_large(n, k, mod):
    result = 1
    while n > 0 or k > 0:
        n_mod = n % mod
        k_mod = k % mod
        if k_mod > n_mod:
            return 0
        result = (result * comb_mod_small(n_mod, k_mod, mod)) % mod
        n //= mod
        k //= mod
    return result

def find_coefficient(a, b, n, k):
    if k > n:
        return 0
    coeff = comb_mod_large(n, k, MOD)  
    coeff = (coeff * mod_exp(a, k, MOD)) % MOD  
    coeff = (coeff * mod_exp(b, n - k, MOD)) % MOD  
    return coeff

a, b, n, k = map(int, input().split())

print(find_coefficient(a, b, n, k))