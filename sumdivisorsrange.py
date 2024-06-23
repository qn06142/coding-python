import math

MOD = 10**9 + 7

def sum_all_divisors(num):
    total_sum = 0
    sqrt_num = int(math.sqrt(num))
    
    for i in range(1, sqrt_num + 1):
        t1 = i * (num // i - i + 1)
        t2 = ((num // i) * (num // i + 1)) // 2 - (i * (i + 1)) // 2
        total_sum += t1 + t2
        total_sum %= MOD
    
    return total_sum

L, R = map(int, input().strip().split())

sum_L_minus_1 = sum_all_divisors(L - 1)
sum_R = sum_all_divisors(R)

result = (sum_R - sum_L_minus_1 + MOD) % MOD
print(result)
