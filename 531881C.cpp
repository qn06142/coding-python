#include<bits/stdc++.h>

using namespace std;
long long dp[105][105], mat[105][105];
int main(){
    long long m, n;
    cin >> m >> n;
    for(long long i = 1; i <= m; i++){
        for(long long j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }
    for(long long j = 1; j <= n; j++) {
        for(long long i = 1; i <= m; i++) {
            dp[j][i] = max(dp[j - 1][i + 1], max(dp[j - 1][i - 1], dp[j - 1][i])) + mat[i][j];
        }
    }
    long long ans = LLONG_MIN;
    for(long long i = 1; i <= m; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
