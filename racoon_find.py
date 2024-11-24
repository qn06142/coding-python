stranddict = dict()
strands = []
for i in range(1, int(input()) + 1):
    inp = input().split()[1]
    stranddict[inp] = i
    strands.append(inp)
def revcom(s):
    out = ''
    for i in s:
        if i == 'A':
            out += 'T'
        elif i == 'T':
            out += 'A'
        elif i == 'G':
            out += 'C'
        else:
            out += 'G'
    out = out[::-1]
    return out
out = []
for i in strands:
    i = revcom(i)
    try:
        stranddict[i]
    except:
        pass
    else:
        out.append(stranddict[i])
if not out:
    print("RACOON ROLL")
    exit()
out.sort()
print(*out)