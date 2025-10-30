def solve(n, s):
    r = 0
    shakes = 0
    for i in range(n):
        if s[i] == '>':
            r += 1
        elif s[i] == '<':
            shakes += r
    return shakes
print(solve(int(input()), input()))
