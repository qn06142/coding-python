#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {

            dp[i][j] = dp[i - 1][j];

            if (j > 0) {
                dp[i][j] = (dp[i][j] + (long long)a[i] * dp[i - 1][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}