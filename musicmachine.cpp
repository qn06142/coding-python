#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long factorial(long long n) {
    if (n == 0) return 1;
    return ((long long) n * (long long) factorial(n - 1)) % MOD;
}
int knapSack(int W, vector<int>& wt, int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(W + 1, 0)));

    dp[0][0][0] = 1; // One way to select 0 items with sum 0
    // Fill dp array
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= W; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0 && k >= wt[i - 1]) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - wt[i - 1]]) % MOD;
                }
            }
        }
    }

    int total_combinations = 0;
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= W; ++k) {
            total_combinations = (total_combinations + ((long long) dp[n][j][k] * (long long)factorial(j)) % MOD) % MOD;
        }
    }

    return total_combinations;
}

signed main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n);
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }
    auto result = knapSack(W, wt, n);
    cout << result << endl;
    return 0;
}