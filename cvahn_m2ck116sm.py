with open("summax.inp" , "r") as f:
    size = int(f.readline())
    arr = list(list(int(i) for i in f.readline().split()) for i in range(0, size))
def calculate_dimensions(x1, y1, x2, y2):
    # print(x1,y1,x2,y2)
    width = (x2 - x1)  #########
    height = (y2 - y1)
    # print(width,height)
    return width+1, height+1

def max_sum_submatrix(matrix):
    if not matrix or not matrix[0]:
        return 0

    rows, cols = len(matrix), len(matrix[0])
    prefix_sums = [[0 for _ in range(cols + 1)] for _ in range(rows + 1)]

    # Calculate prefix sums
    for i in range(1, rows + 1):
        for j in range(1, cols + 1):
            prefix_sums[i][j] = matrix[i - 1][j - 1] + prefix_sums[i - 1][j] + prefix_sums[i][j - 1] - prefix_sums[i - 1][j - 1]

    max_sum = float('-inf')
    max_rect = (0, 0, 0, 0)

    # Find submatrix with max sum
    for i in range(1, rows + 1):
        for j in range(1, cols + 1):
            for k in range(i, rows + 1):
                for l in range(j, cols + 1):
                    curr_sum = prefix_sums[k][l] - prefix_sums[i - 1][l] - prefix_sums[k][j - 1] + prefix_sums[i - 1][j - 1]
                    if curr_sum > max_sum:
                        max_sum = curr_sum
                        max_rect = (i , j , k , l )###############

    return max_sum, max_rect

# Test the function
ans = max_sum_submatrix(arr)
# print(ans)
width, height = calculate_dimensions(ans[1][0],ans[1][1],ans[1][2],ans[1][3])
with open("summax.out", "w") as f:
    f.write(' '.join(map(str, (ans[1][0],ans[1][1],width,height))))
    f.write("\n")
    f.write(str(ans[0]))