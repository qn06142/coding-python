#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;
    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            // delete s[i] alone
            dp[i][j] = 1 + dp[i + 1][j];
            // try to merge with equal characters s[k]
            for (int k = i + 1; k <= j; ++k) {
                if (s[i] == s[k]) {
                    int left = (k == i + 1) ? 0 : dp[i + 1][k - 1];
                    dp[i][j] = min(dp[i][j], left + dp[k][j]);
                }
            }
        }
    }
    cout << (n ? dp[0][n-1] : 0) << '\n';
    return 0;
}
