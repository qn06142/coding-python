from math import isqrt

def A123578(n):
    return isqrt(n<<3)+1>>1

A, B  = map(int, input().split())
print(sum(A123578(i) for i in range(A, B + 1)) % (10 ** 9 + 7))
