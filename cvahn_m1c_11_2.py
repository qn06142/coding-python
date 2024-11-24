with open("daycondn.inp", "r") as f:
	a = int(f.readline())
	b = tuple(map(int, f.readline().split()))
c = []
tmp = []
for i in range(0, len(b)):
	if b[i] <= 0:
		c.append(tmp)
		tmp = []
	else:
		tmp.append(b[i])
c.append(tmp)
tmp = []
with open("daycondn.out", "w") as f:
	f.write(str(len(max(c, key=len))) + "\n")
	out = ''
	for i in max(c, key=len):
		out += str(i) + ' '
	f.write(out[:-1])