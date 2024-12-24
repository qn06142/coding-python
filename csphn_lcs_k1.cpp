#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = 1;
                for(int x = 1; x < i; x++) {
                    for(int y = 1; y < j; y++) {
                        if(a[x] == b[y] and abs(x - i) <= k and abs(y - j) <= k) {
                            dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                        }
                    }
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
