#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, M;
    cin >> n >> M;

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][M] << endl;

    return 0;
}