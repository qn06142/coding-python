#include <iostream>
#include <vector>
using namespace std;
#define int long long
int subCount(vector<int>& arr, int n, int k) {
    vector<int> mod(k, 0);
    int cumSum = 0;

    for (int i = 0; i < n; ++i) {
        cumSum += arr[i];
        mod[((cumSum % k) + k) % k]++;
    }

    int result = 0;
    for (int i = 0; i < k; ++i) {
        if (mod[i] > 1) {
            result += (mod[i] * (mod[i] - 1)) / 2;
        }
    }

    result += mod[0];
    return result;
}

int countSubmatrix(vector<vector<int>>& mat, int m, int n, int k) {
    int tot_count = 0;
    vector<int> temp(m, 0);

    for (int left = 0; left < n; ++left) {
        fill(temp.begin(), temp.end(), 0);
        for (int right = left; right < n; ++right) {
            for (int i = 0; i < m; ++i) {
                temp[i] += mat[i][right];
            }
            tot_count += subCount(temp, m, k);
        }
    }

    return tot_count;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int k = 9;  
    int result = countSubmatrix(matrix, m, n, k);
    cout << result << endl;

    return 0;
}