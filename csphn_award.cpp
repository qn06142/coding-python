#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n+1), pref(n+1,0);
    for (int i=1;i<=n;++i) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1e9));
    vector<vector<int>> prefm(n+1, vector<int>(n+1, -1e9));

    for (int j = 1; j <= n; j++) {
        int x = -1;
        for (int i = 1; i <= j; i++) {
            if (i == 1) {
                dp[i][j] = 1;
            } else {
                long long seg = pref[j] - pref[i-1];           
                long long tar = pref[i-1] - seg;        
                while (x + 1 <= i-2 && pref[x+1] <= tar) x++;
                if (x >= 0) {
                    int k_star = x + 1; 
                    int best_val = prefm[i-1][k_star];
                    if (best_val > -1e9) dp[i][j] = max(dp[i][j], best_val + 1);
                }
            }
        }

        int cur = -1e9;
        for (int k = 1; k <= j; k++) {
            cur = max(cur, dp[k][j]);
            prefm[j][k] = cur;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][n]);
    cout << ans;
}
