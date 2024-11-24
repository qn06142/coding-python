from itertools import permutations
k = int(input().split()[1])
n1 = tuple(permutations([int(i) for i in input().split()], k))
n = []
for i in n1:
    tmp = 1
    for j in i:
        tmp = tmp * j
    n.append(tmp)
print(max(n)%123456789)
