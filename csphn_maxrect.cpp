#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximal_rectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0);
    int max_area = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 'W') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        stack<int> s;
        int max_rect = 0;
        for (int j = 0; j <= n; ++j) {
            while (!s.empty() && (j == n || height[s.top()] >= height[j])) {
                int h = height[s.top()];
                s.pop();
                int w = s.empty() ? j : j - s.top() - 1;
                max_rect = max(max_rect, h * w);
            }
            s.push(j);
        }

        max_area = max(max_area, max_rect);
    }

    return max_area;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << maximal_rectangle(matrix) << endl;
    return 0;
}