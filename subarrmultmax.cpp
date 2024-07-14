#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[(int) 5005], b[(int) 5005], dp[(int) 5005][(int) 5005];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max({dp[i][j], dp[i - 1][j - 1] + a[i] * b[j], a[i] * b[j]});
        }
    }
    int ans = LLONG_MIN;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

}