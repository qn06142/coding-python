def solve(string):
	for index, item in enumerate(string):
		if string.count(item) == 1:
			return index+1
	return -1
with open("XUATHIENDT.INP", "r") as f:
	testcases = tuple(f.readline().strip() for i in range(0, int(f.readline())))
with open("XUATHIENDT.OUT", "w") as f:
	for i in testcases:
		f.write(str(solve(i)) + "\n")