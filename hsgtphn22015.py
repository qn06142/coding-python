a = int(input())
b = input().split()
b = [int(i) for i in b]
c = ""
for i in range(1, a+1):
    c = c + str(max(b[0:i])) + " "
print(c[:-1])
