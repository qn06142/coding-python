MOD = 10**9 + 7

def solve(k: int) -> int:
    if k == 0:
        return 0  

    exp_mod = (pow(2, k-1, MOD-1) - 1) % (MOD-1)
    val = pow(16, exp_mod, MOD)
    ans = (6 * val) % MOD
    return ans

if __name__ == "__main__":
    import sys
    k = int(sys.stdin.read().strip())
    print(solve(k))