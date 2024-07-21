def digit_sum_up_to(n):
    if n < 0:
        return 0

    digits = list(map(int, str(n)))
    length = len(digits)
    dp = [[[-1 for _ in range(2)] for _ in range(9 * length + 1)] for _ in range(length + 1)]

    def dp_solve(pos, sum_so_far, tight):
        if pos == length:
            return sum_so_far
        if dp[pos][sum_so_far][tight] != -1:
            return dp[pos][sum_so_far][tight]

        limit = digits[pos] if tight else 9
        result = 0
        for digit in range(0, limit + 1):
            result += dp_solve(pos + 1, sum_so_far + digit, tight and (digit == limit))

        dp[pos][sum_so_far][tight] = result
        return result

    return dp_solve(0, 0, 1)

def sum_of_digits_in_range(a, b):
    if a > b:
        return 0
    return digit_sum_up_to(b) - digit_sum_up_to(a - 1)

def solve(testcases):
    results = []
    for a, b in testcases:
        results.append(sum_of_digits_in_range(a, b))
    return results

import sys
input = sys.stdin.read
data = input().strip().split()

t = int(data[0])
testcases = [(int(data[i * 2 + 1]), int(data[i * 2 + 2])) for i in range(t)]

results = solve(testcases)

for result in results:
    print(result)