with open("CHUANHOA.INP", "r") as f:
	words = f.read().split()
words = [i.lower().capitalize() for i in words]
with open("CHUANHOA.OUT", "w") as f:
	f.write(' '.join(words))