from itertools import permutations
a = [int(i) for i in input().split()]
list1 = [int(i) for i in range(a[0], a[1]+1)]
for i in list(permutations(list1)):
    outstr = ""
    for j in i:
        outstr += str(j) + ' '
    print(outstr[:-1])
