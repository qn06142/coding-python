with open("DOITLP.inp", "r") as f:
	a = f.read()
with open("DOITLP.OUT", "w") as f:
	f.write(hex(int(a))[2:].upper())