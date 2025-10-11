def f(n):
    if n < 0:
        return 0

    digits = list(map(int, str(n)))
    length = len(digits)
    dp = [[[-1 for _ in range(2)] for _ in range(9 * length + 1)] for _ in range(length + 1)]

    def recur(pos, sum, tight):
        if pos == length:
            return sum
        if dp[pos][sum][tight] != -1:
            return dp[pos][sum][tight]

        limit = digits[pos] if tight else 9
        result = 0
        for digit in range(0, limit + 1):
            result += recur(pos + 1, sum + digit, tight and (digit == limit))

        dp[pos][sum][tight] = result
        return result

    return recur(0, 0, 1)

def calc(a, b):
    if a > b:
        return 0
    return f(b) - f(a - 1)

def solve(tests):
    ans = []
    for a, b in tests:
        ans.append(calc(a, b))
    return ans

import sys
input = sys.stdin.read
data = input().strip().split()

t = int(data[0])
tests = [(int(data[i * 2 + 1]), int(data[i * 2 + 2])) for i in range(t)]

ans = solve(tests)

for result in ans:
    print(result)