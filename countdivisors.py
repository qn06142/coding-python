import math

def has_exactly_three_divisors(n):
    sqrt_n = math.sqrt(n)
    if sqrt_n == int(sqrt_n):
        for i in range(2, int(sqrt_n)):
            if int(sqrt_n) % i == 0:
                return False
        return True
    return False

def solve(A):
    for num in A:
        if has_exactly_three_divisors(num):
            print("YES")
        else:
            print("NO")
n = int(input())
solve([10 ** 12] * 10 ** 6)
