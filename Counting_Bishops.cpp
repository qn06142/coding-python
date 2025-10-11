#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

int cnt(int i) {

    if (i & 1) return (i / 4) * 2 + 1;
    else        return ((i - 1) / 4) * 2 + 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;

    if (k == 0) { cout << 1 << '\n'; return 0; }
    if (k > 2 * n - 1) { cout << 0 << '\n'; return 0; }

    int m = 2 * n; 
    vector<vector<long long>> dp(m, vector<long long>(k + 1, 0));

    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    if (m > 1 && k >= 1) dp[1][1] = 1;

    for (int i = 2; i < m; ++i) {
        int sq = cnt(i); 
        for (int j = 1; j <= k; ++j) {
            long long val = dp[i-2][j]; 
            long long tmp = dp[i-2][j-1] * (long long)(sq - j + 1);
            tmp %= MOD;
            val = (val + tmp) % MOD;
            dp[i][j] = val;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= k; ++i) {
        long long a = dp[m-1][i];
        long long b = dp[m-2][k - i];
        ans = (ans + a * b) % MOD;
    }
    cout << ans << '\n';
}