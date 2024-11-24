#include<iostream>

using namespace std;
int a[(int) 1e5 + 5], dp[(int) 1e5 + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 0; i < 1e5 + 5; i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i > (a[j] - 1)) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << ((dp[n] != (int) 1e9) ? dp[n] : -1);
}