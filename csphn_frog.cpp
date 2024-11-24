#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
    #define int long long
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        dp[0][j] = a[0][j];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int max_prev = 0;

            for (int p = max(0LL, j - k); p <= min(n - 1, j + k); ++p) {
                max_prev = max(max_prev, dp[i - 1][p]);
            }

            dp[i][j] = max_prev + a[i][j];
        }
    }

    int result = *max_element(dp[m-1].begin(), dp[m-1].end());
    cout << result << endl;

    return 0;
}