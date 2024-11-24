p = 10**9+7
mat_mul = lambda A, B: [[sum(i * j for i, j in zip(row, col)) % (p-1) for col in zip(*B)] for row in A]
def eye(m):
    """returns an indentity matrix of order m"""
    identity = [[0] * m for _ in range(m)]
    for i, row in enumerate(identity):
        row[i] = 1
    return identity
def mat_pow(mat, power):
    """returns mat**power"""
    result = eye(len(mat))
    if power == 0:
        return result
 
    while power > 1:
        if power & 1 == 1:
            result = mat_mul(result, mat)
        mat = mat_mul(mat, mat)
        power >>= 1
    return mat_mul(result, mat)
for _ in range(0, int(input())):
    n = int(input())
    A = [[int(i) for i in input().split()] for i in range(0, n)]
    B = [[int(i) % (p - 1) for i in input().split()] for i in range(0, n)]
    A_cubed = mat_pow(A, 3)

    if A_cubed == B:
        print("YES")
    else:
        print("NO")