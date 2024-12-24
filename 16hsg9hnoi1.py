from math import factorial
a, b, c = map(int, input().split())
print(factorial(b) // factorial(a - 1) % c)