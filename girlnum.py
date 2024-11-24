MOD = 10**9 + 7

def digit_dp(pos, tight, lastdig, inc, num, memo):
    if pos == len(num):
        return 1

    if (pos, tight, lastdig, inc) in memo:
        return memo[(pos, tight, lastdig, inc)]

    limit = int(num[pos]) if tight else 9
    result = 0

    if inc == 1:
        for d in range(0, limit + 1):
            if d < lastdig:
                result = (result + digit_dp(pos + 1, tight and d == limit, d, 0, num, memo)) % MOD
    else:
        for d in range(lastdig + 1, limit + 1):
            result = (result + digit_dp(pos + 1, tight and d == limit, d, 1, num, memo)) % MOD

    memo[(pos, tight, lastdig, inc)] = result
    return result

def count_girl_numbers(num):
    memo = {}
    result = 0
    for d in range(1, int(num[0]) + 1):
        result = (result + digit_dp(1, d == int(num[0]), d, 1, num, memo)) % MOD
        result = (result + digit_dp(1, d == int(num[0]), d, 0, num, memo)) % MOD
    return result

def count_in_range(L, R):
    countR = count_girl_numbers(str(R))
    countL = count_girl_numbers(str(L - 1))
    return (countR - countL + MOD) % MOD

from sys import stdin
input_line1 = stdin.read().strip().split()
a = int(input_line1[0])
b = int(input_line1[1])
L = int(input_line1[2])
R = int(input_line1[3])

print(count_in_range(L, R))