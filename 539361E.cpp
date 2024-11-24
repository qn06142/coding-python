#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("arch=skylake,tune=skylake")

const int MAXN = 405;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN], last[MAXN * MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> compress;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            compress.push_back(grid[i][j]);
        }
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            grid[i][j] = lower_bound(compress.begin(), compress.end(), grid[i][j]) - compress.begin() + 1;
        }
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        for(int len = 1; len <= m; len++) {
            for(int i = 1; i <= m - len + 1; i++) {
                int k = i + len - 1;
                if(i < k) {
                    if(grid[j][i] == grid[j][k]) {
                        dp[i][k] = j;
                    }
                    dp[i][k] = max({dp[i][k], dp[i + 1][k], dp[i][k - 1]});
                }
                dp[i][k] = max({dp[i][k], last[grid[j][i]][k], last[grid[j][k]][i]});
                ans = max(ans, (j - dp[i][k]) * (k - i + 1));
            }
        }
        for(int d = 1; d <= m; d++) {
            last[grid[j][d]][d] = j;
        }
    }
    cout << ans << endl;
    return 0;
}