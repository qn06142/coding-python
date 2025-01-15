def calc(n):
    return (n * (1 + n) * (1 + 2 * n)) // 6

a, b, c = map(int, input().split())
print((calc(b) - calc(a - 1)) % c)