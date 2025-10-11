#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;

    vector<int> last(26, 0);
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        long long x = (2LL * dp[i-1]) % MOD;
        if (last[c] > 0) {
            x = (x - dp[ last[c] - 1 ] + MOD) % MOD;
        }
        dp[i] = (int)x;
        last[c] = i;
    }

    cout << dp[n];
}
