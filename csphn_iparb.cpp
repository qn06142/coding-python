#include <iostream>
#include <vector>
using namespace std;
#define int long long
int count(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                dp[i][j] = dp[i-j][j] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[n][n];
}

signed main() {
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}
