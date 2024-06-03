#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(4));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            // If the i-th match is deleted
            dp[i][0] = max(dp[i][0], max(dp[i-1][j], dp[i-1][0]));
            if(s[i-1] == 'W') {
                // If Anvar wins the i-th match
                if(j < 3) {
                    // If it's not the third consecutive win
                    dp[i][j+1] = max(dp[i-1][j], dp[i-1][0]) + 2;
                } else {
                    // If it's the third or more consecutive win
                    dp[i][j] = max(dp[i-1][j], dp[i-1][0]) + 3;
                }
            } else if(s[i-1] == 'D') {
                // If the i-th match is a draw
                dp[i][0] = max(dp[i-1][j], dp[i-1][0]) + 1;
            }
            for(int j = 0; j < 4; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
    }
    int maxPoints = 0;
    for(int j = 1; j <= 4; j++) {
        maxPoints = max(maxPoints, dp[n][j]);
    }
    cout << maxPoints << ' ';
}
