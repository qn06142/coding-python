a = input()
b = input()
na, nb = len(a), len(b)
from string import ascii_lowercase
from collections import Counter as count
table = tuple(ascii_lowercase)
countera = dict(count(a))
counterb = dict(count(b))
dicta = dict()
dictb = dict()
for i in table:
	try:
		countera[i]
	except:
		dicta[i] = 0
	else:
		dicta[i] = countera[i]
for i in table:
	try:
		counterb[i]
	except:
		dictb[i] = 0
	else:
		dictb[i] = counterb[i]
count = 0
for i in table:
	count += abs(dicta[i] - dictb[i])
print(count)