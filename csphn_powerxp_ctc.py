a, b, c = map(int, input().split())

print((pow(a, b, c) * pow(b, a, c)) % c)