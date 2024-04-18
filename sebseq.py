#file shenatigans
fileread = open("subseq.inp", "r")
filewrite = open("subseq.out", "w")
#vars
file = fileread.read()
list1 = file.split()
list1 = [int(i) for i in list1]
a = list1[0:2]
del list1[0:2]
b = list1[0:a[0]]
del list1[0:a[0]]
c = list1[0:a[1]]
e = c.copy()
d = []
outstr = ""
#yea
for i in b:
    if i in c:
        d.append(c.index(i)+1)
        for i in range(0, c.index(i)):
            c[i] = ""
for i in d:
    outstr = outstr + str(i) + " "
#wrting
if len(b) == len(d):
    filewrite.write("YES" + "\n" + outstr[:-1])
else:
    filewrite.write("NO")
filewrite.close()
