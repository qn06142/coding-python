#include<bits/stdc++.h>

using namespace std;
int a[(int) 1e5 + 5];
long long dp[(int) 1e5 + 5], pref[(int) 1e5 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j - i + 1 <= k and j <= n; j++) {
            //cout << i << ' ' << j << endl;
            dp[j] = max(dp[j], dp[i - 2] + pref[j] - pref[i - 1]);
        }
        //cout << dp[i] << ' ';
    }
    cout << dp[n];
}