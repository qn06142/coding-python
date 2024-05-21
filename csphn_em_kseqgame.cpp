#include<iostream>
#include<climits>
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn], b[maxn];
long long dp[10][maxn][maxn];

int main() {
    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int m = 0; m < 10; m++) {
        for(int i = 0; i < maxn; i++) {
            for(int p = 0; p < maxn; p++) {
                if(m == 0) {
                    dp[m][i][p] = 0;
                } else
                //cout << m << " " << i << " " << p << endl;
                dp[m][i][p] = -1e18;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int m = 1; m <= k; m++) {
        for(int i = 1; i <= n; i++) {
            for(int p = 1; p <= n; p++) {
                
                dp[m][i][p] = max(dp[m - 1][i - 1][p - 1] + (long long) a[i] * b[p], max(dp[m][i][p - 1], dp[m][i - 1][p]));
                //cout << m << ' ' << i << ' '<< p << ' ' << dp[m][i][p] << endl;
            }
        }
    }
    cout << dp[k][n][n];
}