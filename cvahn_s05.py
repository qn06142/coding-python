with open("TACHHDT.INP", "r") as f:
	name = f.read().split()
with open("TACHHDT.OUT", "w") as f:
	f.write(name[0] + "\n")
	f.write(' '.join(name[1:-1]) + "\n")
	f.write(name[-1])