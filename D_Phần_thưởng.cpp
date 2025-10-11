#include <bits/stdc++.h>
using namespace std;
static const long long NEG_INF = (long long)(-4e18);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    static long long dp[305][305][305];

    for(int t = 0; t <= k; t++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(t == 0 && i <= j) {
                    dp[t][i][j] = 0;              
                } else {
                    dp[t][i][j] = NEG_INF;        
                }
            }
        }
    }
    for(int i = 1; i <= n+1; i++){
        for(int j = 0; j <= n; j++){
            dp[0][i][j] = 0;
        }
    }

    for(int t = 1; t <= k; t++){

        for(int len = 2*t; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                long long &d = dp[t][i][j];

                d = max(d,
                        dp[t-1][i+2][j]
                      + llabs(a[i] - a[i+1]));

                d = max(d,
                        dp[t-1][i][j-2]
                      + llabs(a[j-1] - a[j]));

                d = max(d,
                        dp[t-1][i+1][j-1]
                      + llabs(a[i] - a[j]));

                d = max(d,
                        dp[t][i+1][j]);

                d = max(d,
                        dp[t][i][j-1]);
            }
        }
    }

    cout << dp[k][1][n] << "\n";
}