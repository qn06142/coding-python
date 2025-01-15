#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(4, -1e18));
    dp[0][0] = 0;

    for (int j = 1; j <= 3; ++j) { 
        for (int i = 1; i <= n; ++i) { 

            dp[i][j] = dp[i - 1][j];
            long long minpref = prefix[i - 1];
            for (int k = i; k >= 1; --k) {
                minpref = min(minpref, prefix[k - 1]);
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + (prefix[i] - minpref));
            }
        }
    }

    cout << dp[n][3] << endl;
    return 0;
}
