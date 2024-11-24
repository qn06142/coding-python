#include<iostream>

using namespace std;
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5], dp[(int) 1e5 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(pref[j] - pref[i - 1] >= 0) {
                dp[i] += dp[j - 1];
            }
        }
    }
    cout << dp[n];
}