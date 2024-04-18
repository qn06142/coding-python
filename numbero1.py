#importing modules
import math
#defining variables
input = int(input())
a = 0
b = 0
for i in range(0, input):
    a = i
    for j in range(0, input):
        b = input - j
        print(a, b)
        if a + b is input:
            print("this", a, b)
            if a/b < 1:
                if math.gcd(a, b) == 1:
                    print("there:", a, b)
                    break
print("here:", a, b)
