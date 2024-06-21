#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5];
signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int minpref = LONG_LONG_MAX;
    int ans = LONG_LONG_MIN;
    for(int i = 1; i <= n; i++){
        minpref = min(minpref, pref[i]);
        ans = max(ans, pref[i] - minpref);
    }
    cout << ans;
}