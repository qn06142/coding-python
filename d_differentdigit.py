import sys

a, b = map(int, sys.stdin.readline().split())

def count_valid(n_str):
    length = len(n_str)
    memo = {}

    def dp(index, tight, last_digit):
        if index == length:
            return 1
        key = (index, tight, last_digit)
        if key in memo:
            return memo[key]

        upper = int(n_str[index]) if tight else 9

        lower = 1 if index == 0 else 0

        ans = 0
        for digit in range(lower, upper + 1):
            if digit != last_digit:
                ans += dp(index + 1,
                            tight and (digit == upper),
                            digit)

        memo[key] = ans
        return ans

    total = sum(9 * (9 ** (l - 1)) for l in range(1, length))

    total += dp(0, True, -1)
    return total

def count_up_to(n):
    return 0 if n <= 0 else count_valid(str(n))

print(count_up_to(b) - count_up_to(a - 1))