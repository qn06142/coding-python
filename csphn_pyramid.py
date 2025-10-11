import sys

def roll(i, n):
    return (i + n - 1) % n + 1

def char_map(c):
    if 'A' <= c <= 'Z':
        return ord(c) - ord('A')
    return -1

def getoff(row):
    return (row * (row - 1)) // 2 + 1

def getpos(i, j):
    offset = getoff(i)
    return offset + (j - 1) if i % 2 == 1 else offset + (i - j)

input = sys.stdin.read
data = input().splitlines()

n = int(data[0])
s = data[1].upper()
length = len(s)
q = int(data[2])

prefm = [[0] * (length + 1) for _ in range(26)]

for i in range(length):
    mapi = char_map(s[i])
    if mapi != -1:
        prefm[mapi][i + 1] += 1
        
for c in range(26):
    for i in range(1, length + 1):
        prefm[c][i] += prefm[c][i - 1]
results = []
for line in data[3:]:
    t, *args = line.split()
    args = list((int(args[0]), args[1]))
    t = int(t)
    if t == 1:
        i = args[0]
        target = args[1]
        mapi = char_map(target)
        if mapi == -1:
            results.append(0)
            continue
        
        offset = getoff(i)
        start = 1
        end = i
        
        startm = roll(getpos(i, 1), length)
        endm = roll(getpos(i, i), length)
        if i % 2 == 0:
            startm, endm = endm, startm
        
        fulrep = (i - 1) // length
        count = fulrep * prefm[mapi][length]
        if startm <= endm:
            count += prefm[mapi][endm] - prefm[mapi][startm - 1]
        else:
            count += prefm[mapi][length] - prefm[mapi][startm - 1]
            count += prefm[mapi][endm]
        results.append(count)
    
    elif t == 2:
        i, j = args
        j = int(j)
        pos = getpos(i, j)
        result = s[(pos - 1) % length]
        results.append(result)
print('\n'.join(map(str, results)))