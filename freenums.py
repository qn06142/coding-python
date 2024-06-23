def is_palindrome(s):
    return s == s[::-1]

def digit_dp(pos, tight, leading_zero, state, num_str, memo):
    if pos == len(num_str):
        return 1
    
    if (pos, tight, leading_zero, state) in memo:
        return memo[(pos, tight, leading_zero, state)]
    
    limit = int(num_str[pos]) if tight else 9
    count = 0
    
    for digit in range(0, limit + 1):
        new_tight = tight and (digit == limit)
        new_leading_zero = leading_zero and (digit == 0)
        new_state = state
        
        if not new_leading_zero:
            new_state += str(digit)
            if len(new_state) > 1 and is_palindrome(new_state):
                continue
            if len(new_state) > 2:
                new_state = new_state[1:]

        count += digit_dp(pos + 1, new_tight, new_leading_zero, new_state, num_str, memo)
    
    memo[(pos, tight, leading_zero, state)] = count
    return count

def count_free_numbers(L, R):
    def count_up_to(n):
        if n < 0:
            return 0
        num_str = str(n)
        memo = {}
        return digit_dp(0, True, True, "", num_str, memo)
    
    return count_up_to(R) - count_up_to(L - 1)

L = int(input().strip())
R = int(input().strip())
print(count_free_numbers(L, R))
