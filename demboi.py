def fileread(file):
    with open(file, "r") as f:
        return f.read()

def filewrite(file, cont):
    with open(file, "w") as f:
        f.write(str(cont))

inp = [int(i) for i in fileread("demboi.inp").split()]
k = inp[0]
m = inp[1]
n = inp[2]
count = 0
setdivsk = {i for i in range(k, n, k)}
setdivsm = {i for i in range(m, n, m)}
for i in range(min(k, m), n+1):
    if i in setdivsm or i in setdivsk:
        count += 1

filewrite("demboi.out", count)
