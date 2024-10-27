#include <bits/stdc++.h>
using namespace std;

const int MAX_S = 10000;
const int INF = 1e9;

int main() {

    int s, n;
    cin >> s >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(MAX_S + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= MAX_S; ++j) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    int result = INF;
    for (int i = s; i <= MAX_S; ++i) {
        if (dp[i] != INF) {
            result = min(result, dp[i] + dp[i - s]);
        }
    }

    cout << result << endl;

    return 0;
}