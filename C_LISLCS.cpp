#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 555;
const int maxm = 555;

int a[maxn], b[maxm];
int dp[maxn][maxm], pre[maxn][maxm];

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) cin >> b[i];

    // Initialize arrays
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = pre[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        int ma = 0, p = 0;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = pre[i - 1][j];
            if (a[i] == b[j]) {
                if (dp[i][j] < ma + 1) {
                    dp[i][j] = ma + 1;
                    pre[i][j] = p;
                }
            } else if (b[j] < a[i]) {
                if (ma < dp[i - 1][j]) {
                    ma = dp[i - 1][j];
                    p = j;
                }
            }
        }
    }

    int ans = 0, pos = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < dp[n][i]) {
            ans = dp[n][i];
            pos = i;
        }
    }
    cout << ans - 1 << endl;
}
