with open("LATGACH.INP", "r") as f:
	size = [int(i) for i  in f.readline().split()]
	pattern = [[int(i) for i in f.readline().split()] for _ in range(0, size[0])]
blacksqrt = (3,1,0,2)
whitesqrt = (2,0,1,3)
countblack = 0
countwhite = 0
for j in range(0, size[0]-1):
	for i in range(0, size[1]-1):
		currmask = (pattern[j][i],pattern[j][i+1],pattern[j+1][i],pattern[j+1][i+1])
		if blacksqrt == currmask:
			countblack += 1
		if whitesqrt == currmask:
			countwhite += 1
with open("LATGACH.out", "w") as f:
	f.write(str(countblack) + ' ' + str(countwhite))