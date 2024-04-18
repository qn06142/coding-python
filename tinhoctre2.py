inp = input().split()
a = int(inp[0])
b = int(inp[1])
c = 0
for i in range(0, 10**3):
    if a > b:
        print(c)
        break
    c = c+1
    a = a*3
    b = b*2
