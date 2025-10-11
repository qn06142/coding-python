def f(n):
    if n < 0:
        return 0

    digits = list(map(int, str(n)))
    length = len(digits)

    from functools import lru_cache

    @lru_cache(None)
    def recur(pos, tight):
        if pos == length:
            return (1, 0)

        limit = digits[pos] if tight else 9
        count = 0
        sum = 0
        for d in range(limit + 1):
            cnt, ssum = recur(pos + 1, tight and (d == limit))
            count += cnt
            sum += ssum + cnt * d
        return (count, sum)

    return recur(0, True)[1]

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