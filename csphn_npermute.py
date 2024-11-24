from itertools import permutations
list1 = [int(i) for i in range(1, int(input())+1)]
for i in list(permutations(list1)):
    outstr = ""
    for j in i:
        outstr += str(j) + ' '
    print(outstr[:-1])
