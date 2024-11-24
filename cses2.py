n = int(input())
inplist = input().split()
inplist = [int(i) for i in inplist]
inplist = set(inplist)
flag = True
for i in range(0, n-1):
    if i+1 not in inplist:
        print(i+1)
        flag = False
        break
if flag:
    print(n)
