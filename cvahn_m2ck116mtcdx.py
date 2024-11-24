#note: code only in c++ will work without tle, see bottom
def isSymmetric(mat, N):
    for i in range(N):
        for j in range(N):
            if (mat[i][j] != mat[j][i]):
                return False
    return True
def get_square_submatrices(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    submatrices = []

    for x in range(rows):
        for y in range(cols):
            size = min(rows - x, cols - y)
            for s in range(size):
                submatrix = [row[y:y+s+1] for row in matrix[x:x+s+1]]
                submatrices.append(submatrix)
    return submatrices
def find_submatrix(matrix, submatrix):
    # Get dimensions of input matrix and submatrix
    matrix_rows, matrix_cols = len(matrix), len(matrix[0])
    submatrix_rows, submatrix_cols = len(submatrix), len(submatrix[0])

    # Iterate over the main matrix
    for i in range(matrix_rows - submatrix_rows + 1):
        for j in range(matrix_cols - submatrix_cols + 1):
            # Check if the submatrix is found
            if all(matrix[i + x][j + y] == submatrix[x][y] for x in range(submatrix_rows) for y in range(submatrix_cols)):
                return (i, j)  # Return the position of the submatrix

    return None  # Return None if submatrix is not found

a = [[int(i) for i in input().split()] for _ in range(0, int(input()))]
matrices = []
for i in get_square_submatrices(a):
	if len(i) <= 1:
		continue
	if isSymmetric(i, len(i)):
		matrices.append(i)
pos = find_submatrix(a, max(matrices, key= len))
print(pos[0] +1, pos[1] +1, len(max(matrices, key= len)))
"""
#include <iostream>
#include <vector>
using namespace std;

bool isSymmetric(vector<vector<int>>& mat) {
    int N = mat.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> find_largest_symmetric_submatrix(vector<vector<int>>& matrix, int& max_size) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    max_size = 0;
    pair<int, int> max_pos = make_pair(-1, -1);

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            int size = min(rows - x, cols - y);
            for (int s = 0; s < size; s++) {
                vector<vector<int>> submatrix;
                for (int i = x; i <= x + s; i++) {
                    vector<int> row(matrix[i].begin() + y, matrix[i].begin() + y + s + 1);
                    submatrix.push_back(row);
                }
                if (isSymmetric(submatrix) && submatrix.size() > max_size) {
                    max_size = submatrix.size();
                    max_pos = make_pair(x, y);
                }
            }
        }
    }
    return max_pos;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int max_size;
    pair<int, int> pos = find_largest_symmetric_submatrix(a, max_size);
    cout << pos.first + 1 << " " << pos.second + 1 << " " << max_size << endl;

    return 0;
}
"""