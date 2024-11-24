from math import factorial
n, k = (int(i) for i in input().split())
print(str(factorial(n))[:k])