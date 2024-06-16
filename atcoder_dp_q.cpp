#include<bits/stdc++.h>
using namespace std;
#define int long long
int bit[200005], dp[200005];
int a[200005], h[200005];
int n;
void update(int u, int v) {
    while(u <= n) {
        bit[u] = max(bit[u], v);
        u += (u & (-u));
    }
}
int query(int u) {
    int ans = 0;
    while(u) {
        ans = max(ans, bit[u]);
        u -= (u & (-u));
    }
    return ans;
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = a[i];
        dp[i] = max(dp[i], query(h[i] - 1) + a[i]);
        update(h[i], dp[i]);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}