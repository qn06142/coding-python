def isperfect(inp):
    inp = int(inp)
    divisors = []
    
    for i in range(1, inp+1):
        if not inp%i:
            divisors.append(i)
    if sum(divisors[:-1])==inp:
        return True
    else:
        return False
perfects = []
out = ""
for i in range(int(open("hoanhao.inp","r").read().split()[0]),int(open("hoanhao.inp","r").read().split()[1])):
    if isperfect(i):
        perfects.append(i)
for i in perfects:
    out+=str(i)+" "
open("hoanhao.out","w").write(out)
open("hoanhao.out","w").close()
