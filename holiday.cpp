#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n);
    for (int i = 0; i < 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i] = {a, b, c};
    }

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i] = {a + max(dp[i - 1][1], dp[i - 1][2]), b + max(dp[i - 1][2], dp[i - 1][0]), c + max(dp[i - 1][0], dp[i - 1][1])};
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

    return 0;
}

