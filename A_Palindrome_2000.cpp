#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // dp[i][j] = số chèn tối thiểu để s[i..j] thành palindrome
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len = độ dài chuỗi con
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                // nếu len == 2 thì dp[i+1][j-1] = dp[i+1][i] = 0 vẫn đúng
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }

    cout << dp[0][n-1] << "\n";
}
