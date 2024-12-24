MOD = 10**9 + 7

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    results = []
    
    for i in range(1, t + 1):
        n = int(data[i])
        
        power_of_two = mod_exp(2, n - 1, MOD)
        
        result = (n * power_of_two) % MOD
        results.append(result)
    
    sys.stdout.write("\n".join(map(str, results)) + "\n")
solve()