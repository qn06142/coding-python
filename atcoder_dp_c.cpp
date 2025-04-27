#include<iostream>
#include<algorithm>
using namespace std;
int dp[(int) 1e5 + 5][4];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1] + a, dp[i - 1][2] + a);
        dp[i][1] = max(dp[i - 1][0] + b, dp[i - 1][2] + b);
        dp[i][2] = max(dp[i - 1][0] + c, dp[i - 1][1] + c);
    }
    cout << *max_element(dp[n], dp[n] + 3);
}