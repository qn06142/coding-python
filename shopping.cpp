#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

    for (const auto& item : items) {
        int a_i = item.first;
        int b_i = item.second;

        for (int i = x; i >= 0; --i) {
            for (int j = y; j >= 0; --j) {

                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a_i);
                }

                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + b_i);
                }
            }
        }
    }

    cout << dp[x][y] << endl;

    return 0;
}