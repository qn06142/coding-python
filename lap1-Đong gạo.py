#imports
from math import ceil
#vars
inp = int(input())
bigbag = 5
smolbag = 3
maxbigbags = 0
possiblebagsamount = []
#yea
if (inp)%bigbag==0:
    possiblebagsamount.append(inp//bigbag)
maxbigbags = inp//bigbag
for i in range(5,maxbigbags*bigbag+1,bigbag):
    #print(i)
    #print((inp-i)%smolbag)
    if (inp-i)%smolbag == 0:
        possiblebagsamount.append(int(i/bigbag+(inp-i)/smolbag))
if possiblebagsamount:
    print(min(possiblebagsamount))
else:
    print(-1)
