def count_zeros_up_to(n):
    if n < 0:
        return 0  # No zeros in negative range
    s = str(n)
    L = len(s)
    dp = [[[-1 for _ in range(L + 1)] for __ in range(2)] for ___ in range(L + 1)]
    
    def digit_dp(pos, tight, cnt_zeros, leading):
        if pos == L:
            return cnt_zeros
        
        if dp[pos][tight][cnt_zeros] != -1:
            return dp[pos][tight][cnt_zeros]
        
        limit = int(s[pos]) if tight else 9
        res = 0
        
        for digit in range(0, limit + 1):
            new_tight = tight and (digit == limit)
            new_leading = leading and (digit == 0)
            new_cnt_zeros = cnt_zeros + (1 if digit == 0 and not new_leading else 0)
            res += digit_dp(pos + 1, new_tight, new_cnt_zeros, new_leading)
        
        dp[pos][tight][cnt_zeros] = res
        return res
    
    return digit_dp(0, 1, 0, True)

def count_zeros_in_range(a, b):
    if a == 0:
        return count_zeros_up_to(b) + 1  # Include the zero itself
    return count_zeros_up_to(b) - count_zeros_up_to(a - 1)

# Reading input
import sys
input = sys.stdin.read
data = input().strip().split()

t = int(data[0])
index = 1
results = []

for _ in range(t):
    a = int(data[index])
    b = int(data[index + 1])
    index += 2
    results.append(count_zeros_in_range(a, b))

for result in results:
    print(result)