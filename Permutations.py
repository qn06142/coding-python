from itertools import permutations
s = input()
print(list(''.join(i) for i in set(permutations(s, len(s)))))