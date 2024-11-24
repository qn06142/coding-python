n = int(input())
output = str(n) + " "
while n != 1:
    if n % 2 == 0:
        n = int(n / 2)
        output = output + str(n) + " "
    else:
        n = int(3*n + 1)
        output = output + str(n) + " "
print(output)
