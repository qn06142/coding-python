n = int(input())
output = 0
while n != 1:
    if n % 2 == 0:
        n = int(n / 2)
        output+=1
    else:
        n = int(3*n + 1)
        output+=1
print(output)
