#include<bits/stdc++.h>

using namespace std;
const int maxn = (int) 2e3 + 5;
int a[maxn][maxn], dp[maxn][maxn];
signed main() {
    int m, n, k;
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for(int _ = 0; _ < k; _++) {
        int t, l, b, r;
        cin >> t >> l >> b >> r;
        a[t][l]++;
        a[b + 1][r + 1]++;
        a[b + 1][l]--;
        a[t][r + 1]--;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i - 1][j];
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == a[i - 1][j] and a[i][j] == a[i][j - 1] and a[i][j] == a[i - 1][j - 1]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            } else dp[i][j] = 1;
        }
    }/*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int maxdp = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            maxdp = max(maxdp, dp[i][j]);
        }
    }
    cout << maxdp;
}