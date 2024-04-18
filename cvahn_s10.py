with open("KITUKN.INP", "r") as f:
	string = f.read().lower().strip()
stringset = set(string)
with open("KITUKN.OUT", "w")  as f:
	f.write(str(len(stringset)))