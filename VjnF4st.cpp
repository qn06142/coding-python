#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
#define int long long
long long findMinDays(int n, long long X, vector<int>& a) {
    long long ans = INF;
    // Initialization
    for (int k = 1; k <= n; ++k) {
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(n+1, -INF)));
        dp[1][1][a[1] % k] = a[1];
        for (int i = 2; i <= n; ++i) {
            for (int r = 0; r < k; ++r) {
                dp[i][1][r] = dp[i-1][1][r];
            }
            dp[i][1][a[i] % k] = max(dp[i][1][a[i] % k], (long long) a[i]);
        }

        // DP update
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= i; ++j) {
                for (int r = 0; r < k; ++r) {
                    dp[i][j][r] = max(dp[i - 1][j][r], dp[i-1][j-1][(r - a[i] % k + k) % k] + a[i]);
                }
            }
        }

        // Calculate answer
        if ((X - dp[n][k][X % k]) % k == 0) {
            ans = min(ans, (X - dp[n][k][X % k]) / k);
        }
    }

    return ans == INF ? -1 : ans;
}

signed main() {
    int n;
    long long X;
    cin >> n >> X;
    
    vector<int> a(n+1); // Adjusting the size of a for one-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    cout << findMinDays(n, X, a) << endl;
    
    return 0;
}
