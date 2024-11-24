#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define int long long
int kadane(const vector<int>& arr) {
    int max_end_here = 0, max_so_far = INT_MIN;
    for (int x : arr) {
        max_end_here = max(x, max_end_here + x);
        max_so_far = max(max_so_far, max_end_here);
    }
    return max_so_far;
}

int find(const vector<vector<int>>& matrix, int n, int m) {
    int maxsum = INT_MIN;
    for (int row1 = 0; row1 < n; ++row1) {
        vector<int> temp(m, 0);
        for (int row2 = row1; row2 < n; ++row2) {
            for (int col = 0; col < m; ++col) {
                temp[col] += matrix[row2][col];
            }
            maxsum = max(maxsum, kadane(temp));
        }
    }
    return maxsum;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << find(matrix, n, m) << endl;
    return 0;
}