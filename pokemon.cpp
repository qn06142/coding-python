#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5 + 5;
const int MAXK = 1e5 + 5;
int n, m, k, dp[2][MAXK];
long long prefix[MAXK];
long long cal() {
    int max_k = (n < 100? k : 100);
    for (int i = 0; i <= max_k; ++i) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= max_k; ++j) {
            prefix[j] = dp[0][j] + (j - i >= 0? prefix[j - i] : 0);
            dp[1][j] = min(prefix[j] - (j - (m + 1) * i >= 0? prefix[j - (m + 1) * i] : 0), 1LL * INF);
            // cerr << i << ' ' << j << " : " << dp[1][j] << '\n';
        }
        for (int j = 0; j <= max_k; ++j) {
            dp[0][j] = dp[1][j];
        }
    }
    long long ans = 0;
    int k1 = k;
    for (int j = 0; j <= max_k; ++j) {
        k1 -= dp[0][j];
        if (k1 > 0) {
            ans += 1LL * j * dp[0][j];
        }
        else {
            k1 += dp[0][j];
            ans += 1LL * k1 * j;
            return ans;
        }
    }
    return -1;
}
signed main() {
    #ifdef LOCAL
        // freopen("TEST.inp", "r", stdin);
        // freopen("test.out", "w", stdout);
    #else
        // freopen("TEST.inp", "r", stdin);
        // freopen("TEST.out", "w", stdout);
    #endif
    int t;
    cin >> t;
    // int t = 1;
    while (t--) {
        cin >> n >> m >> k;
        cout << cal() << '\n';
    }
    return 0;
}
