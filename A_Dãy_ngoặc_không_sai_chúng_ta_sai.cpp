#include <bits/stdc++.h>
using namespace std;
<<<<<<< Updated upstream
const int MOD = 1e9 + 7;

int dp[510][510][510];
bool visited[510][510][510];
int solve(int l, int r, int v, const string &s) {
    if (l > r) return v >= 0 ? 1 : 0;
    if (v < 0) return 0;

    if (visited[l][r][v]) return dp[l][r][v];
    visited[l][r][v] = true;

    int &res = dp[l][r][v];
    res = 0;

    res = (solve(l + 1, r, v, s) + solve(l, r - 1, v, s) - solve(l + 1, r - 1, v, s) + MOD) % MOD;

    if (s[l] != s[r] and v + (s[l] == '(' ? 1 : -1) >= 0) {
        res = (res + solve(l + 1, r - 1, v + (s[l] == '(' ? 1 : -1), s)) % MOD;
    }
    //cerr << l << ' '  << r << ' ' << v << ' ' << res << '\n';
    //cerr << s.substr(l, r - l + 1) << '\n';
    return res;
}
=======
#define int long long
const int MOD = 1e9 + 7;

int dp[2][510][510];
>>>>>>> Stashed changes

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
<<<<<<< Updated upstream

    memset(visited, 0, sizeof(visited));
    int result = (solve(0, n - 1, 0, s) - 1 + MOD) % MOD;
    cout << result << '\n';
=======
    s = " " + s;
    for(int l = n + 1; l >= 0; l--) {
        memset(dp[l & 1], 0, sizeof dp[l & 1]);
        for(int r = 0; r <= n; r++) {
            for(int v = 0; v <= n + 1; v++) {
                if(l > r) {
                    dp[l & 1][r][v] = v >= 0;
                    continue;
                }
                if((l == n + 1) or (r == 0)) {
                    continue;
                }
                dp[l & 1][r][v] = (dp[(l + 1) & 1][r][v] + dp[l & 1][r - 1][v] - dp[(l + 1) & 1][r - 1][v] + MOD) % MOD;
                if(s[l] != s[r] and v + (s[l] == '(' ? 1 : -1) >= 0) {
                    dp[l & 1][r][v] += dp[(l + 1) & 1][r - 1][v + (s[l] == '(' ? 1 : -1)];
                }
                dp[l & 1][r][v] %= MOD;
            }
        }
    }
    cout << (dp[1][n][0] - 1 + MOD) % MOD << '\n';
>>>>>>> Stashed changes

    return 0;
}
