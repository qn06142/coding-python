#include<bits/stdc++.h>

using namespace std;
#define int long long
int dp[(int) 1e4 + 5][20], a[(int) 1e4 + 5], bit[(int) 1e4 + 5];
int n;
void update(int u, int v) {
    while(u) {
        bit[u] += v;
        bit[u] %= (int) 1e9;
        u -= (u & (-u));
    }
}
int query(int u) {
    int ans = 0;
    while(u <= 1e4 + 5) {
        ans += bit[u];
        ans %= (int) 1e9;
        u += (u & (-u));
    }
    return ans;
}
signed main() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> compress(n);
    for(int i = 0; i < n; i++) {
        compress[i] = a[i + 1];
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
    }
    for(int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }
    for(int k_ = 2; k_ <= k; k_ ++) {
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; i++) {
            dp[i][k_] = query(a[i] + 1);
            update(a[i], dp[i][k_ - 1]);
            /*
            for(int j = 1; j < i; j++) {
                if(a[j] > a[i]) {
                    dp[i][k_] += dp[j][k_ - 1];
                    dp[i][k_] %= (int) 1e9;
                }
            }*/
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i][k];
        ans %= (int) 1e9;
    }
    cout << ans;
}