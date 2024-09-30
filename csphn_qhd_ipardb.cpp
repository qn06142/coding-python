#include <iostream>
using namespace std;
#define int long long
const int MAX_N = 401;
int dp[MAX_N][MAX_N];

signed main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 1;  
        for (int j = i - 1; j >= 1; --j) {
            dp[i][j] = dp[i][j + 1];  
            if (i >= j) {
                dp[i][j] += dp[i - j][j];  
            }
        }
    }

    cout << dp[n][1] << endl;

    return 0;
}