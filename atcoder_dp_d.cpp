#include<bits/stdc++.h>
using namespace std;
const int maxn = 105, maxw = (int) 1e5 + 5;
int val[maxw];
int wt[maxw];
long long dp[maxn][maxw];
int main() {
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        wt[i] = tmp;
        val[i] = tmp1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (wt[i-1] <= j)
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]],  dp[i-1][j]);
            else
                    dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][w];
    return 0;
}