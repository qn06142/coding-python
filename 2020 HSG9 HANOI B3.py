s = list(input())
from string import digits
digits = set(digits)
for index, item in enumerate(s):
	if s[index] not in digits:
		s[index] = ' '
s = ''.join(s).split()
checks = []
from itertools import combinations
for index, item in enumerate(s):
	checks.extend (int(s[index][i:j]) for i in range(0, len(s[index])) for j in range(i+1, len(s[index])+1))
checks.sort()
checks.reverse()
for i in checks:
	if all(i%j != 0 for j in range(2, i//2 +1)):
		print(i)
		break
	