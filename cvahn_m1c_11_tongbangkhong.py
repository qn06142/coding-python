with open("TONGBANGKHONG.INP", "r") as f:
	f.readline()
	a = set(map(int, f.readline().split()))
count = 0
for i in a:
	if i<0:
		if abs(i) in a:
			count += 1
with open("TONGBANGKHONG.OUT", "w") as f:
	f.write(str(count))