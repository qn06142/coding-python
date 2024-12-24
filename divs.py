n = int(input())
from itertools import combinations
from math import gcd


def lcm(a, b):
    return a * b // gcd(a, b)

def lcm_of_list(nums):
    result = nums[0]
    for num in nums[1:]:
        result = lcm(result, num)
    return result


divisors = [2, 3, 4, 5, 6, 7, 8, 9, 10]

ans = 0

for i in range(1, len(divisors) + 1):  
    for subset in combinations(divisors, i):
        lcm_value = lcm_of_list(subset)
        if i % 2 == 1:  
            ans += n // lcm_value
        else:           
            ans -= n // lcm_value


result = n - ans
print(result)
