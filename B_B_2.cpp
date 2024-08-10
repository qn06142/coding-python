#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    vector<long long> diag1(m + n, 0);  
    vector<long long> diag2(m + n, 0);  

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            diag1[i - j + n - 1] += board[i][j];
            diag2[i + j] += board[i][j];
        }
    }

    long long maxSum = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            long long currentSum = diag1[i - j + n - 1] + diag2[i + j] - board[i][j];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum << endl;
    return 0;
}