with open("THONGKE.INP", "r") as f:
	f.readline()
	a = tuple(map(int, f.readline().split()))
b = [0 for _ in range(0, max(a)+1)]
for i in a:
	b[i] += 1
with open("thongke.out", "w") as f:
	for i in range(0, len(b)):
		if b[i]:
			f.write(str(i) + ":" + str(b[i])+ "\n")