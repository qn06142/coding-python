def sol(inp):
	arrarr = []
	tmp = []
	for i in inp:
		if i <0:
			tmp.append(i)
		else:
			arrarr.append(tmp)
			tmp = []
	arrarr.append(tmp)
	arrarr= [sum(i) for i in arrarr]
	if min(arrarr) <0 :
		return min(arrarr)
	else:
		return 0
testcases = []
with open("DAYCONAMNN.INP", "r") as f:
	for _ in range(0, int(f.readline())):
		f.readline()
		testcases.append(tuple(map(int,f.readline().split())))
with open("DAYCONAMNN.OUT", "w") as f:
	for i in testcases:
		f.write(str(sol(i)))
		f.write("\n")