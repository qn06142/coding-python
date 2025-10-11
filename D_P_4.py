MOD = 10**9 + 7

def mat_mult(A, B):
    return [
        [(A[0][0]*B[0][0] + A[0][1]*B[1][0]) % MOD, (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % MOD],
        [(A[1][0]*B[0][0] + A[1][1]*B[1][0]) % MOD, (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % MOD]
    ]

def mat_pow(M, n):

    R = [[1,0],[0,1]]
    while n > 0:
        if n & 1:
            R = mat_mult(R, M)
        M = mat_mult(M, M)
        n >>= 1
    return R

def cnt(n):
    M = [[19, 6],
         [7,  20]]
    P = mat_pow(M, n)

    return P[0][0] % MOD

n = int(input().strip())
print(cnt(n))