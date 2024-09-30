#include<bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#define int long long
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            int sum = pref[i + 1] - pref[j];
            ans = max(ans, (sum >= k) ? (sum / (i - j + 1)) : 0);
            if(sum < k) break;
        }
    }

    cout << ans << endl;
    return 0;
}