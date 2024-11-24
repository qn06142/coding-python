MOD = 123456789

def bpow(n, k, mod):
    res = 1
    while k:
        if k & 1:
            res = res * n % mod
        n = n * n % mod
        k >>= 1
    return res

def comb(a, b, mod):
    p = pow(10, b[0], mod)
    p = p * a[1] % mod
    p = (p + b[1]) % mod
    return ((a[0] + b[0]) % 82260072, p)

def precompute():
    dp = [[(0, 0)] * 100003 for _ in range(10)]
    for i in range(10):
        dp[i][0] = (1, i)
    for j in range(1, 100002):
        for i in range(10):
            if i * 3 < 10:
                dp[i][j] = dp[i * 3][j - 1]
            else:
                dp[i][j] = comb(dp[(i * 3) // 10][j - 1], dp[(i * 3) % 10][j - 1], MOD)
    return dp

def main():
    import sys
    input = sys.stdin.readline
    dp = precompute()
    t = int(input())
    for _ in range(t):
        k, n = input().split()
        n = int(n)
        res = dp[int(k[-1])][n]
        for i in range(len(k) - 2, -1, -1):
            res = comb(dp[int(k[i])][n], res, MOD)
        print(res[1])

if __name__ == "__main__":
    main()