#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("arch=skylake")
#define int long long
int a[5005];
pair<int, int> dp[5005];
int important[5005];
const pair<int, int> mod = {1e9 + 7, 1e9 + 9};
pair<int, int> operator%(pair<int, int> a, pair<int, int> m) {
    return {(a.first + m.first) % m.first, (a.second + m.second)% m.second};
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second) % mod;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first - b.first, a.second - b.second) % mod;
}
void operator+=(pair<int, int> &a, pair<int, int> b) {
    a = a + b;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        for(int s = k; s >= a[i]; s--) {
            dp[s] += dp[s - a[i]]; 
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int s = a[i]; s <= k; s++) {
            dp[s] = dp[s] - dp[s - a[i]]; 
        }
        for(int s = max(0LL, k - a[i]); s < k; s++) {
            important[i] = important[i] || (dp[s] != make_pair(0LL, 0LL));
        }
        for(int s = k; s >= a[i]; s--) {
            dp[s] += dp[s - a[i]]; 
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << important[i];
    }

    return 0;
}
