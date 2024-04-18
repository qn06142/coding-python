from math import ceil
from math import sqrt
#fileread = open("nguyento.inp", "r")
#filewrite = open("nguyento.OUT", "w")
#n = int(fileread.read())
n= int(input())
primelist = [2]
def primechecker(n):
    flag = False
    for i in range(2, ceil(sqrt(n))+1):
        if n%i == 0:
            flag = True
            return False
    return True
for i in range(3, n):
    if primechecker(i):
        primelist.append(i)
print(primelist)
#filewrite.write(str(len(primelist)))
#filewrite.close()
