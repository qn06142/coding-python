#include<bits/stdc++.h>

using namespace std;
long long a[(int) 1e3 + 5], dp[(int) 1e3 + 5][(int) 1e3 + 5];
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long inf = -1e18;

    for(int i = 0; i < (int) 1e3 + 5; i++) {
        for(int j = 0; j < (int) 1e3 + 5; j++) {
            dp[i][j] = inf;
        } 
    }
    dp[0][x] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < x; j++) {
            for(int p = 1; p <= k; p++) {
                if(i  - p < 0) break;
                if(dp[i - p][j + 1] == inf) {continue;}
                dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + a[i]);
            }
        } 
    }
    long long ans = inf;
    for(int i = n - k + 1; i <= n; i++) {
        ans = max(ans, *max_element(dp[i], dp[i] + x));
        //cout << *max_element(dp[i], dp[i] + x) << endl;
    }
    cout << (ans != inf ? ans : -1);
}