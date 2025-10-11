#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2);       // a[1..n]
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // S[i] is prefix sum
    vector<int> S(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        S[i] = S[i - 1] + a[i];

    // dp[i][j] = min cost to cut a[i..j]
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> opt(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INF;

            int start = opt[l][r - 1];
            int end = opt[l + 1][r];
            if (start > end) swap(start, end);

            for (int k = start; k <= end; ++k) {
                int cost = dp[l][k] + dp[k + 1][r];
                if (cost < dp[l][r]) {
                    dp[l][r] = cost;
                    opt[l][r] = k;
                }
            }
            dp[l][r] += S[r] - S[l - 1];
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}
