#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5];

signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n - m; i++) {
        ans = max(ans, pref[i + m] - pref[i]);
    }
    cout << ans;
}