import re
bruh = ' ' + input()
nigger = int(input())
bruh = bruh * nigger
nlen = len(bruh)
yaxis = 3
print()
def printballs(lines):
    for _ in range(lines):
       print(bruh)
air = re.sub('.', ' ', bruh)
air = air + bruh*3
printballs(yaxis)
for _ in range(yaxis):
    print(air)
printballs(yaxis)
