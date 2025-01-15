#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define int long long
#define debug(x) cerr << #x << ": " << x << endl;

int32_t main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N + 1);
    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 1e18));

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    dp[1][0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[1][i] = max(dp[1][i - 1], a[i]);
    }

    for (int i = 2; i <= K; ++i) {
        stack<pair<int, int>> stacc;  
        for (int j = i; j <= N; ++j) {
            int cur = dp[i - 1][j - 1];  

            while (!stacc.empty() && a[stacc.top().second] <= a[j]) {
                cur = min(cur, stacc.top().first);
                stacc.pop();
            }

            dp[i][j] = min(dp[i][stacc.empty() ? 0 : stacc.top().second], cur + a[j]);

            stacc.push(make_pair(cur, j));
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}