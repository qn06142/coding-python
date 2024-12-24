x, n, m = (int(i) for i in input().split())

def calcsum(n, x):
    memo = {}
    
    def helper(n, x):
        if n == 1:
            return 10**x % m
        if n in memo:
            return memo[n]
        
        mid = n // 2
        left_sum = helper(mid, x) % m
        right_sum = helper(n - mid, x) % m
        
        shift = mid * x
        result = (left_sum + right_sum * pow(10, shift, m)) % m
        memo[n] = result
        return result
    
    return helper(n, x)
result = calcsum(n - 1, len(str(x)))
print((result + 1) * x % m)