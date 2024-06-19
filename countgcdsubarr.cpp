#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    // Create a 2D DP table initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize base case: sequences of length 1
    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;
    }

    // Fill the DP table
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = j; k <= m; k += j) {
                dp[i][k] = (dp[i][k] + dp[i-1][j]) % MOD;
            }
        }
    }

    // Calculate the result
    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}