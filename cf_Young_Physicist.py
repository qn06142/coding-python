inp = [[int(i) for i in input().split()] for _ in range(int(input()))]
currvect = [0, 0, 0]
for i in inp:
	for j in range(0, 3):
		currvect[j] += i[j]
if currvect != [0, 0, 0]:
	print("NO")
else:
	print("YES")