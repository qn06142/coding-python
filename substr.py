inp = input()
inp1 = input()
shift = len(inp1)
for i in range(0, len(inp)-shift+1):
	if inp[i:i+shift] == inp1:
		print(i+1)