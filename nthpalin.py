def ten(x):
    return 1 if x == 0 else 10 ** (x - 1)

n = int(input())

if n == 1:
    print(0)
    exit(0)

n -= 1

d = 1
while True:
    x = (d + 1) // 2
    max_palindromes = 9 * ten(x)
    if n < max_palindromes:
        start_number = ten(x) + n - 1
        s = list(str(start_number))
        s.extend([' '] * (d - len(s)))
        for i in range(x, d):
            s[i] = s[d - 1 - i]
        print(''.join(s))
        exit(0)
    else:
        n -= max_palindromes
    d += 1
