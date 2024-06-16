#include<bits/stdc++.h>

using namespace std;
#define int long long
int dp[(int) 1e5 + 5], a[(int) 1e5 + 5], pref[(int) 1e5 + 5], bit[(int) 1e5 + 5];
const int mod = 1e9 + 9;
void update(int u, int v) {
    while(u <= 1e5 + 5) {
        bit[u] += v;
        bit[u] %= mod;
        u += u & (-u);
    }
}
int query(int u) {
    int ans = 0;
    while(u) {
        ans += bit[u];
        ans %= mod;
        u -= u & (-u);
    }
    return ans;
}
signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> compress(pref, pref + 1 + n);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 0; i <= n; i++) {
        pref[i] = upper_bound(compress.begin(), compress.end(), pref[i]) - compress.begin() + 1;
    }
    dp[0] = 1;
    update(pref[0], 1);
    for(int i = 1; i <= n; i++) {
        dp[i] = query(pref[i]);
        update(pref[i], dp[i]);/*
        for(int j = 1; j <= i; j++) {
            if(pref[i] >= pref[j - 1]) {
                dp[i] += dp[j - 1];
                dp[i] %= (int) 1e9 + 9;
            }
        }*/
    }
    cout << dp[n];
}