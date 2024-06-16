MOD = 10**9 + 7

def count_pleasant(n):
    s = str(n)
    length = len(s)
    dp = [[[-1] * 10 for _ in range(2)] for _ in range(length)]
    
    def dfs(pos, tight, last_digit):
        if pos == length:
            return 1
        if dp[pos][tight][last_digit] != -1:
            return dp[pos][tight][last_digit]
        
        limit = int(s[pos]) if tight else 9
        res = 0
        for digit in range(last_digit, limit + 1):
            res += dfs(pos + 1, tight and (digit == limit), digit)
            res %= MOD
        
        dp[pos][tight][last_digit] = res
        return res
    
    return dfs(0, 1, 0)

def pleasant_numbers(a, b):
    result_b = count_pleasant(b)
    result_a = count_pleasant(a - 1)
    return (result_b - result_a) % MOD
with open("pleasant.inp", "r") as f:
    a, b = map(int, f.readline().split())
with open("pleasant.out", "w") as f:
    f.write(str(pleasant_numbers(a, b)))