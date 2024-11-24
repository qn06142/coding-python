#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_A = 100; 
const int MAX_N = 100; 
int val[MAX_A + 1]; 
int f[MAX_A + 1][MAX_A + 1]; 
int dp[MAX_N + 1][MAX_A * MAX_N + 1]; 

signed main() {
    freopen("WOOD.INP", "r", stdin);
    freopen("WOOD.OUT", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    memset(val, 0, sizeof(val));
    for (int i = 0; i < m; ++i) {
        int d, x;
        cin >> d >> x;
        val[d] = max(val[d], x); 
    }

    for (int x = 1; x <= MAX_A; ++x) {
        for (int i = 0; i <= x; ++i) {
            if (i == 0) {
                f[x][i] = val[x]; 
            } else {
                f[x][i] = 0;
                for (int y = 1; y < x; ++y) {
                    f[x][i] = max(f[x][i], f[x - y][i - 1] + val[y]);
                }
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= MAX_A * n; ++j) {
            for (int k = 0; k <= min(j, a[i - 1]); ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + f[a[i - 1]][k]);
            }
        }
    }


    int total_length = accumulate(a.begin(), a.end(), 0);
    int max_profit = 0;
    for (int i = 0; i <= total_length; ++i) {
        max_profit = max(max_profit, dp[n][i] - i * (i + 1) / 2); 
    }

    cout << max_profit << endl;

    return 0;
}