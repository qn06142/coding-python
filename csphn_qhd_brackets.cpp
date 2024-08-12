#include <iostream>
#include <vector>
using namespace std;

const int MOD = 123456789;

int solve(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (j < k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    
    return dp[n][0];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << (solve(n, k) - solve(n, k - 1) + MOD) % MOD << endl;
    return 0;
}