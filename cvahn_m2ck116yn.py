with open("yenngua.inp", "r") as f:
	a = tuple([int(i) for i in f.readline().split()])
	b = tuple([tuple(map(int, f.readline().split())) for _ in range(0, a[0])])
def minColumn(my_list):

    m = len(my_list)
    n = len(my_list[0])

    list2 = []  # stores the column wise minimas
    for col in range(n):  # iterate over all columns
        col_min = my_list[0][col]  # assume the first element of the column(the top most) is the minimum
        for row in range(1, m):  # iterate over the column(top to down)

            col_min = min(col_min, my_list[row][col]) 

        list2.append(col_min)
    return tuple(list2)
mincols = minColumn(b)
maxrows = [max(i) for i in b]
ans = []
for row, maxrow in enumerate(maxrows):
	for col, mincol in enumerate(mincols):
		if maxrow == mincol:
			ans.append(str(row+1) + " " + str(col+1))
with open("yenngua.out", "w") as f:
	if ans:
		f.write(' '.join(ans))
	else:
		f.write("0")