with open("NNNCONANG.INP", "r") as f:
	a = int(f.readline())
	testcases = []
	for _  in range(0, a):
		f.readline()
		testcases.append(tuple(map(int, f.readline().split())))
ans = []
for i in testcases:
	currmaxheight = 0
	redlight = 0
	for j in i:
		if j >= currmaxheight:
			currmaxheight = max(currmaxheight, j)
			redlight += 1
	ans.append(redlight)
ans = [str(i) + "\n" for i in ans]
with open("NNNCONANG.OUT", "w") as f:
	f.writelines(ans)