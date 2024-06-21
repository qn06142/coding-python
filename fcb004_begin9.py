def last_digit(a, b):
    a = int(a)
    b = int(b)
     
    # if a and b both are 0
    if a == 0 and b == 0:
        return 1
       
    # if exponent is 0
    if b == 0:
        return 1
       
    # if base is 0
    if a == 0:
        return 0
       
    # if exponent is divisible by 4 that means last
    # digit will be pow(a, 4) % 10.
    # if exponent is not divisible by 4 that means last
    # digit will be pow(a, b%4) % 10
    if b % 4 == 0:
        res = 4
    else:
        res = b % 4
         
    # Find last digit in 'a' and compute its exponent
    num = pow(a, res)
     
    # Return last digit of num
    return num % 10
from sys import stdin

a, b = stdin.read().split()
print(last_digit(a,b))