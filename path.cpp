#include<iostream>

using namespace std;

int a[105][105], dp[105][105];

int main() {
    int m, n;
    cin >> m >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            dp[i][j] = min(dp[i][j + 1], min(dp[i - 1][j + 1], dp[i + 1][j + 1])) + 1;
        }
    }
    cout << dp[m][n];
}