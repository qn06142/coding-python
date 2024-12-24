#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;
const int MAX_N = 105;

int n, m;
int dp[MAX_N][1 << 13];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        int mask_limit = (1 << (2 * m + 1)); 

        for (int i = 1; i <= n; ++i) {
            for (int mask = 0; mask < mask_limit; ++mask) {
                if (!dp[i - 1][mask]) continue; 
                int pre_mask = mask >> 1;

                for (int t = 0; t <= 2 * m; ++t) {
                    int x = i + t - m;

                    if (x >= 1 && x <= n && !(pre_mask & (1 << t))) {
                        int new_mask = pre_mask | (1 << t);
                        dp[i][new_mask] = (dp[i][new_mask] + dp[i - 1][mask]) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (int mask = 0; mask < mask_limit; ++mask) {
            ans = (ans + dp[n][mask]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
