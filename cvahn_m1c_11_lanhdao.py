import sys
 

# Function to print all elements which are greater than all
# elements present to their right
def find(arr):
	out = []
	if not arr:
		return []
	
	max_so_far = -sys.maxsize
	for i in reversed(arr):
		if i >= max_so_far:
			max_so_far = i
			out.append(str(i))
	print(' '.join(reversed(out)))
sys.stdin = open("LANHDAO.INP", "r")
#sys.stdout = open("LANHDAO.OUT", "w")
for i in range(0, int(input())):
	input()
	find([int(i) for i in input().split()])
#sys.stdout.close()