MOD = 1000000007

# Initialize DP table
dp = [[[-1 for _ in range(2)] for _ in range(40)] for _ in range(20)]
a = []
n = 0

def binomial_coeff(n, k):
    res = 1
    if k > n - k:
        k = n - k
    for i in range(k):
        res *= (n - i)
        res //= (i + 1)
    return res

def catalan(n):
    c = binomial_coeff(2 * n, n)
    return c // (n + 1)

def find_ways(n):
    if n % 2 == 1:
        return 0
    return catalan(n // 2)

def recur(pos, balance, tight):
    if pos == n and balance == 0:
        return 1
    if pos == n or balance < 0:
        return 0
    if dp[pos][balance + n][tight] != -1:
        return dp[pos][balance + n][tight]

    ans = 0
    limit = a[pos] if tight else 1

    if limit >= 1:
        ans += recur(pos + 1, balance + 1, tight and (a[pos] == 1))
        ans %= MOD

    if limit >= -1:
        ans += recur(pos + 1, balance - 1, tight and (a[pos] == -1))
        ans %= MOD

    dp[pos][balance + n][tight] = ans
    return ans

if __name__ == "__main__":
    s = input().strip()
    n = len(s)
    a = [1 if c == '(' else -1 for c in s]

    dp = [[[-1 for _ in range(2)] for _ in range(len(a) * 2)] for _ in range(len(a) + 1)]
    
    result = find_ways(n) - recur(0, 0, True) + 1
    result %= MOD

    print(result)
