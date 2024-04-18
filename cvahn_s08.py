with open("DEMXAU.INP", "r") as f:
	key = f.readline().strip()
	search = f.readline()
indexes = []
for i in range(0, len(search)-len(key)+1):
	print(search[i:i+len(key)])
	if search[i:i+len(key)] == key:
		indexes.append(i+1)
with open("DEMXAU.OUT", "w") as f:
	f.write(str(len(indexes)) + "\n" + ' '.join(map(str, indexes)))