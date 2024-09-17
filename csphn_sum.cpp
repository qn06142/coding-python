#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];  
            if (i >= j) {
                dp[i][j] += dp[i - j][j];  
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}