with open("chkshop.inp", "r") as f:
	f.readline()
	a = sorted([int(i) for i in f.readline().split()])
	b = sorted([int(i) for i in f.readline().split()])
with open("chkshop.out", "w") as f:
	f.write("YES" if all(a[i] == b[i] for i in range(0, len(a))) else "NO")