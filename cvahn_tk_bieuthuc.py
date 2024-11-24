calcs = []
tmp1 = ('+', '-', '*', '/')
for i1 in tmp1:
	for i2 in tmp1:
		for i3 in tmp1:
			for i4 in tmp1:
				calcs.append((i1, i2, i3, i4))
a, b, c, d, e, m = tuple(open("Bieuthuc.inp", "r").read().split())
for i in calcs:
	tmp = 0
	exec('tmp = ' + '((((' + a + i[0] + b + ')' + i[1] + c + ')' + i[2] + d + ')' + i[3] + e + ')')
	if tmp == int(m):
		with open("Bieuthuc.out", "a") as f:
			f.write('((((' + a + i[0] + b + ')' + i[1] + c + ')' + i[2] + d + ')' + i[3] + e + ')' + '\n')