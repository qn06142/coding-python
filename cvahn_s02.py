with open("tinhtong.inp", "r") as f:
	inp = f.read()
numberos = []
tmp = ""
for i in inp:
	try:
		int(i)
		tmp += i
	except:
		if tmp:
			numberos.append(int(tmp))
			tmp = ''
with open('tinhtong.out', 'w') as f:
	f.write(str(sum(numberos)))