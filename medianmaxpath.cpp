#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int max_median(int n, int m, vector<vector<int>> a) {
    int l = 0;
    int r = n * m;

    while (r - l > 1) {
        vector<vector<int>> atmp(n + 1, vector<int>(m + 1, -1));
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        int mid = (l + r) / 2;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i - 1][j - 1] >= mid) {
                    atmp[i][j] = 1;
                } else {
                    atmp[i][j] = -1;
                }
            }
        }
        dp[1][1] = atmp[1][1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                dp[i][j] = INT_MIN;
                if (i > 1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + atmp[i][j]);
                }
                if (j > 1) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + atmp[i][j]);
                }
            }
        }
        if (dp[n][m] > 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    cout << max_median(n, m, a) << endl;
    return 0;
}