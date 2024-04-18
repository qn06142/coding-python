#files crap
fileread = open("BEADS.inp", "r")
filewrite = open("BEADS.OUT", "w")
#vars
inp = fileread.read().split()
n = inp[0]
inp.pop(0)
shells = [int(i) for i in inp]
chain = shells[:1]
#doing stuff
for i in shells:
    if i == chain[0] or i == chain[-1]:
        continue
    if i > chain[-1]:
        chain.append(i)
    else:
        chain.insert(0, i)
filewrite.write(str(len(chain)))
filewrite.close()
