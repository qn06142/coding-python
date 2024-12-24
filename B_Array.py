MOD = 998244353

def solve(N, K, A):
    max_mask = (1 << K)  
    freq = [0] * max_mask

    for a in A:
        freq[a] += 1

    dp = [0] * max_mask
    for mask in range(max_mask):
        dp[mask] = freq[mask]

    for bit in range(K):  
        for mask in range(max_mask):
            if mask & (1 << bit):  
                dp[mask] += dp[mask ^ (1 << bit)]

    F = [0] * max_mask
    for x in range(max_mask):
        for submask in range(x + 1):
            if (submask & x) == submask and dp[submask] > 0:
                F[x] = submask
                break

    result = sum(F) % MOD
    return result

N, K = map(int, input().split())
A = list(map(int, input().split()))

print(solve(N, K, A))