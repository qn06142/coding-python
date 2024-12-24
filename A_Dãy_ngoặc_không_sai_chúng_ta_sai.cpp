#include <bits/stdc++.h>
using namespace std;
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    memset(visited, 0, sizeof(visited));
    int result = (solve(0, n - 1, 0, s) - 1 + MOD) % MOD;
    cout << result << '\n';

    return 0;
}
