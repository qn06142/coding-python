
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n), d(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> d[i];

    vector<int> dp(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (h[j] >= h[i] + d[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result << endl;

    return 0;
}