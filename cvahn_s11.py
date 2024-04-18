def divisorstring(string):
	divisors = []
	size = len(string)
	for i in range(1, len(string)+1):
		if not size % i:
			divisors.append(i)
	for i in divisors:
		if len(set(string[j:j+i] for j in range(0, len(string), i))) == 1:
			return tuple(set(string[j:j+i] for j in range(0, len(string), i)))[0]
with open("uocchuoi.inp", "r") as f:
	inp = f.read().strip()
with open("uocchuoi.out", "w") as f:
	f.write(divisorstring(inp))