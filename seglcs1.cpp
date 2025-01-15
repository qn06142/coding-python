#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifdef ONLINE_JUDGE
const int maxn = 1005;
#else
const int maxn = 10;
#endif

int dp[maxn][maxn][11]; 

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;

    s = " " + s;
    t = " " + t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int d = 1; d <= k; d++) {

                dp[i][j][d] = max(dp[i - 1][j][d], dp[i][j - 1][d]);

                int len = 0;
                while (i - len > 0 && j - len > 0 && s[i - len] == t[j - len]) {
                    dp[i][j][d] = max(dp[i][j][d], dp[i - len - 1][j - len - 1][d - 1] + len + 1);
                    len++;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j][k]);
        }
    }

    cout << ans << endl;
    return 0;
}