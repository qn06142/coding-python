#include<iostream>
#include<algorithm>
#include<numeric>
#include<climits>

using namespace std;
long long a[(int) 5e3 + 5], b[(int) 5e3 + 5], dp [(int) 5e3 + 5] [(int) 5e3 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    long long ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + a[i] * b[j], a[i] * b[j]);
            
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}