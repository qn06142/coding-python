#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0);
    int maxArea = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 'W') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        stack<int> s;
        int maxRect = 0;
        for (int j = 0; j <= n; ++j) {
            while (!s.empty() && (j == n || height[s.top()] >= height[j])) {
                int h = height[s.top()];
                s.pop();
                int w = s.empty() ? j : j - s.top() - 1;
                maxRect = max(maxRect, h * w);
            }
            s.push(j);
        }

        maxArea = max(maxArea, maxRect);
    }

    return maxArea;
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
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
