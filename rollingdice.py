#files shenatigans
fileread = open("ROLLING.INP", "r")
filewrite = open("ROLLING.OUT", "w")
#vars
inp = fileread.read().split()
n = int(inp[0])
k = int(inp[1])
listoftsides = [6,4,1,3]
ksteps = []
ksum = 0
outsum = 0
#yeah
for i in range(0,k):
    ksteps.append(listoftsides[i%4])
ksum = sum(ksteps)
while n != 0:
    if n >= k:
        outsum += ksum
        n -= k
    else:
        for i in range(n):
            outsum += ksteps[i]
        n -= n
filewrite.write(str(outsum))
filewrite.close()
