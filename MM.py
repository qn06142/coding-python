with open("MM.INP", "r") as f:
	inp = f.read().lower()
from string import ascii_lowercase as lowercase
for i in lowercase:
	inp = inp.replace(i, ' ')
inp = [int(i) for i in inp.split()]
with open("MM.OUT", "w") as f:
	f.write(str(len(inp)))