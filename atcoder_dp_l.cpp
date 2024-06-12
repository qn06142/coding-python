#include<iostream>

using namespace std;
long long a[(int) 3e3 + 5], dp[(int) 3e3 + 5][(int) 3e3 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for(int i = n; i > 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n];
}