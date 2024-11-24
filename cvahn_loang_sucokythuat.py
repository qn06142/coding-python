m, n = map(int, input().split())
cheese = [[False for _ in range(n+2)]]+[[False]+[True if i == "1" else False for i in input().split()]+[False] for _ in range(m)]+[[False for _ in range(n+2)]]
todel = [[False for i in j] for j in cheese]
count = 0
while sum(sum(cheese, [])) > 0:
	count += 1
	for irow in range(1, m+1):
		for icol in range(1, n+1):
			if sum((cheese[irow][icol+1],cheese[irow+1][icol],cheese[irow][icol-1],cheese[irow-1][icol])) <= 2 and cheese[irow][icol] == True:
				todel[irow][icol] = True
	for i in range(1, m+1):
		for j in range(1, n+1):
			if todel[i][j]:
				cheese[i][j] = False
				todel[i][j] = False
print(count)