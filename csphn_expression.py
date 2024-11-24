from math import gcd
#vars
inp = input()
inp = "print(" + inp + ")"
def SUM(a ,b):
    return a+b
def DIF(a,b):
    return a-b
def MAX(a,b):
    return max(a,b)
def MIN(a,b):
    return min(a,b)
def GCD(a,b):
    return gcd(a,b)
exec(inp)
