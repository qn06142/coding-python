#ifdef DEBUG
#pragma GCC optimize("trapv")
#endif
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n_, m_, k;
int dp[(int) 5e3 + 5][(int) 5e3 + 5];
int solve(int n, int m) {
    if(n < 0 or m < 0) {
        return 0;
    }
    if(n == 0) return dp[n][m] = 1;
    if(dp[n][m] != -1) return dp[n][m];
    return ((solve(n, m - 1) + solve(n - m, m) % mod - solve(n - m - k, m - 1)) % mod);
}
signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n_ >> m_ >> k;
    for(int i = 0; i <= 5e3 + 4; i++) {
        for(int j = 0; j <= 5e3 + 4; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << solve(n_, m_) << endl;
}