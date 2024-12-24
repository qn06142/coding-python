mod = int(1e9 + 7)

def binpow(a, b, m):
    a %= m
    res = 1
    while b > 0:
        if b & 1:
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res

def countsquares(m, n):
    if m < n:
        m, n = n, m
    return n * (n + 1) * (3 * m - n + 1) * binpow(6, mod - 2, mod) % mod

if __name__ == "__main__":
    m, n = map(int, input().split())
    print(countsquares(m, n))

