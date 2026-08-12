#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
bool check(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (cin >> s && s != "end") {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (check(s[i], s[j])) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }

        cout << dp[0][n - 1] << "\n";
    }
}