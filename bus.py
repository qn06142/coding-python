#file shenatigans
fileread = open('BUS.INP', 'r')
filewrite = open('BUS.OUT', 'w')
#funcs and imports
from math import ceil
def stepify(a,b):
    return (ceil(a/b))
#vars
inp = fileread.read().split()
inp = [int(i) for i in inp]
n = inp[0]
t = inp[1]
d = inp[2]
del inp[:3]
outstr = ""
#yeah
for i in inp:
    if i <= t:
        outstr = outstr + "1" + " "
        continue
    else:
        i = i - t
        outstr = outstr + str(ceil(i/d+1)) + " "
print(outstr[:-1])
#filewrite.close()
