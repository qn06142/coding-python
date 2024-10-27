import sys
sys.setrecursionlimit(1000000000);
MOD = int(1e9 + 7)

# Initialize large DP table and digit array
dp = [[[[ -1 for _ in range(100)] for _ in range(2)] for _ in range(2)] for _ in range(10000)]
a = [0] * 100000

def recur(i, tight, validzero, summ):
    if i < 0:
        return summ % 3 == 0
    if not tight and dp[i][tight][validzero][summ] != -1:
        return dp[i][tight][validzero][summ]
    
    newlim = a[i] if tight else 9
    res = 0
    
    for c in range(newlim + 1):
        res += recur(i - 1, tight and (c == a[i]), validzero or (c > 0), (summ + c * c) % 3)
        res %= MOD
    
    if not tight:
        dp[i][tight][validzero][summ] = res
    
    return res

def f(x):
    n = 0
    while x > 0:
        a[n] = x % 10
        x //= 10
        n += 1
    return recur(n - 1, 1, 0, 0)

def main():
    input = sys.stdin.read
    data = input().split()
    results = []

    n = int(data[0]) - 1
    
    # Reset DP table for each query
    for i in range(len(dp)):
        for j in range(2):
            for k in range(2):
                for l in range(100):
                    dp[i][j][k][l] = -1
    
    results.append(f(n) % MOD)
    
    print(' '.join(map(str, results)))

if __name__ == "__main__":
    main()
