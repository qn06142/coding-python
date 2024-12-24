#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, k;
int dp[(int) 2e5 + 5], pref[(int) 2e5 + 5], ans[(int) 2e5 + 5];
void add(int & a, int b) {
    a = (a + b >= mod ? a + b - mod : a + b);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int curr = k;
    dp[0] = 1, pref[0] = 1;
    for (int i = 1; i <= n; i++) {
        pref[i] = dp[i];
        if (i >= k) add(pref[i], pref[i - k]);
        dp[i] = (i < k ? 0 : pref[i - k]);
        add(ans[i], dp[i]);
    }
    k++;
    curr += k;
    for (; curr <= n; curr += k) {
        dp[0] = pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = dp[i];
            if (i >= k) add(pref[i], pref[i - k]);
            dp[i] = (i < k ? 0 : pref[i - k]);
            add(ans[i], dp[i]);
        }
        k++;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}