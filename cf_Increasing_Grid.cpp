#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MOD = 998244353;

int solve(int n, int m, vector<vector<int>>& table) {
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    dp[n + 1][1] = 1; // Start from the bottom-left corner (n+1, 1) in one-based indexing

    for (int i = n + 1; i >= 1; --i) {
        for (int j = 1; j <= m + 1; ++j) {
            if (i <= n && table[i][j] != 0) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
            }
            if (j > 1 && table[i][j] != 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[1][m + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> results;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> table(n + 1, vector<int>(m + 1, -1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> table[i][j];
            }
        }

        // Transform the table
        bool valid = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (table[i][j] != -1) {
                    table[i][j] -= (i + j - 1);
                    if (table[i][j] != 0 && table[i][j] != 1) {
                        valid = false;
                    }
                }
            }
        }

        if (!valid) {
            results.push_back(0);
            continue;
        }

        // Propagate values
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (table[i][j] == 1) {
                    if (i + 1 <= n && table[i + 1][j] == -1) table[i + 1][j] = 1;
                    if (j + 1 <= m && table[i][j + 1] == -1) table[i][j + 1] = 1;
                } else if (table[i][j] == 0) {
                    if (i > 1 && table[i - 1][j] == -1) table[i - 1][j] = 0;
                    if (j > 1 && table[i][j - 1] == -1) table[i][j - 1] = 0;
                }
            }
        }

        // Count valid configurations
        int result = solve(n, m, table);
        results.push_back(result);
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}
