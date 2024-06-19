#include<bits/stdc++.h>

using namespace std;
int dp[(int) 2e3 + 5][(int) 2e3 + 5];
int main() {
    string a, b;
    cin >> a >> b;
    int x = a.size();
    int y = b.size();
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j ++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[x][y];
}