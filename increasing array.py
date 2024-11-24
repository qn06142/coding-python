input()
inp = [int(i) for i in input().split()]
flag = False
moves = 0
while not flag:
    for i in range(0, len(inp)-1):
        print(i)
        if inp[i] < inp[i+1]:
            inp[i+1] = inp[i]
            moves += inp[i] - inp[i+1]
            print(inp[i+1] , inp[i])
    if sorted(inp[:-2]) == inp[:-2]:
        flag = True
