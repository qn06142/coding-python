def get_diagonals(matrix):
    # Get matrix dimensions
    rows, cols = len(matrix), len(matrix[0])

    # Initialize lists to store diagonals
    diagonals_tl_br, diagonals_tr_bl, diagonals_bl_tr, diagonals_br_tl = [], [], [], []

    # Get diagonals from top-left to bottom-right
    for r in range(rows):
        diagonals_tl_br.append([matrix[i][i - r] for i in range(r, min(rows, cols + r)) if 0 <= i - r < cols])
    for c in range(1, cols):
        diagonals_tl_br.append([matrix[i - c][i] for i in range(c, min(rows + c, cols)) if 0 <= i - c < rows])

    # Get diagonals from top-right to bottom-left
    for r in range(rows):
        diagonals_tr_bl.append([matrix[i][r - i] for i in range(r + 1) if 0 <= r - i < cols])
    for c in range(1, cols):
        diagonals_tr_bl.append([matrix[i][cols - 1 - (i - c)] for i in range(c, min(rows + c, cols)) if 0 <= cols - 1 - (i - c) < cols])

    # Get diagonals from bottom-left to top-right
    for r in range(rows):
        diagonals_bl_tr.append([matrix[rows - 1 - i][i - r] for i in range(r, min(rows, cols + r)) if 0 <= i - r < cols])
    for c in range(1, cols):
        diagonals_bl_tr.append([matrix[rows - 1 - (i - c)][i] for i in range(c, min(rows + c, cols)) if 0 <= i - c < rows])

    # Get diagonals from bottom-right to top-left
    for r in range(rows):
        diagonals_br_tl.append([matrix[rows - 1 - i][cols - 1 - (i - r)] for i in range(r, min(rows, cols + r)) if 0 <= cols - 1 - (i - r) < cols])
    for c in range(1, cols):
        diagonals_br_tl.append([matrix[rows - 1 - (i - c)][cols - 1 - i] for i in range(c, min(rows + c, cols)) if 0 <= cols - 1 - i < cols])

    return diagonals_tl_br, diagonals_tr_bl, diagonals_bl_tr, diagonals_br_tl


size = int(input())
rows = [[i == "1" for i in tuple(input())] for _ in range(0, size)]
cols = [[rows[j][i] for j in range(size)] for i in range(size)]
diags = [get_diagonals(rows)]
currbest = 0

def findbest(arr):
	lens = 0
	tmp = 0
	for i in arr:
		if i :
			tmp += 1
		else:
			lens = max(tmp, lens)
			tmp = 0
	lens = max(tmp, lens)
	return  lens
for i in cols:
	currbest = max(currbest, findbest(i))
for i in rows:
	currbest = max(currbest, findbest(i))
for i in diags:
	for j in i:
		for k in j:
			currbest = max(currbest, findbest(k))
print(currbest)