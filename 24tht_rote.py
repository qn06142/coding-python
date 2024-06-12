def rotate_matrix(matrix):
    matrix1 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    matrix1[0][0] = matrix[1][0]
    matrix1[0][1] = matrix[0][0]
    matrix1[0][2] = matrix[0][1]
    matrix1[1][0] = matrix[2][0]
    matrix1[1][1] = matrix[1][1]
    matrix1[1][2] = matrix[0][2]
    matrix1[2][0] = matrix[2][1]
    matrix1[2][1] = matrix[2][2]
    matrix1[2][2] = matrix[1][2]
    return matrix1
def reverse_rotate_matrix(matrix):
    matrix1 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    matrix1[0][0] = matrix[0][1]
    matrix1[0][1] = matrix[0][2]
    matrix1[0][2] = matrix[1][2]
    matrix1[1][0] = matrix[0][0]
    matrix1[1][1] = matrix[1][1]
    matrix1[1][2] = matrix[2][2]
    matrix1[2][0] = matrix[1][0]
    matrix1[2][1] = matrix[2][0]
    matrix1[2][2] = matrix[2][1]
    return matrix1

mat = [[int(i) for i in input().split()] for _ in range(0, 3)]
int(input())
for i in (int(i) for i in input().split()):
    
    if i == 1:
        submat = []
        for i in mat:
            submat.append(i[:3])
        #print(submat)
        submat = rotate_matrix(submat)
        for i in range(0, 3):
            for j in range(0, 3):
                mat[i][j] = submat[i][j]
    else:
        submat = []
        for i in mat:
            submat.append(i[1:4])
        #print(submat)
        submat = reverse_rotate_matrix(submat)
        for i in range(0, 3):
            for j in range(1, 4):
                mat[i][j] = submat[i][j - 1]
    #print(submat)
    #print(mat)
for i in mat:
    print(*i)