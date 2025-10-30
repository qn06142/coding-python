#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("arch=skylake")
#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 205; 

static char grid[maxn][maxn][maxn]; 

static bool z_[maxn][maxn][maxn];
static bool y_[maxn][maxn][maxn];
static bool x_[maxn][maxn][maxn];

static bool comb[maxn][maxn];
static int dp[maxn][maxn];

int calcz(int depth, int n, int m) {

    int ans1 = 0;
    for (int s = 1; s <= depth; ++s) {

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                comb[i][j] = z_[s][i][j];

        for (int t = s; t <= depth; ++t) {
            if (t > s) {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j)
                        comb[i][j] = comb[i][j] & z_[t][i][j];
            }

            int maxs = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (comb[i][j]) {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                        maxs = max(maxs, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

            int b = t - s + 1;
            ans1 = max(ans1, maxs * b);
        }
    }
    return ans1;
}

int calcy(int depth, int n, int m) {

    int ans1 = 0;
    for (int s = 1; s <= depth; ++s) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                comb[i][j] = y_[s][i][j];

        for (int t = s; t <= depth; ++t) {
            if (t > s) {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j)
                        comb[i][j] = comb[i][j] & y_[t][i][j];
            }

            int maxs = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (comb[i][j]) {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                        maxs = max(maxs, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

            int b = t - s + 1;
            ans1 = max(ans1, maxs * b);
        }
    }
    return ans1;
}

int calcx(int depth, int n, int m) {

    int ans1 = 0;
    for (int s = 1; s <= depth; ++s) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                comb[i][j] = x_[s][i][j];

        for (int t = s; t <= depth; ++t) {
            if (t > s) {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j)
                        comb[i][j] = comb[i][j] & x_[t][i][j];
            }

            int maxs = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (comb[i][j]) {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                        maxs = max(maxs, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

            int b = t - s + 1;
            ans1 = max(ans1, maxs * b);
        }
    }
    return ans1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, q, r;
    cin >> p >> q >> r;

    for (int y = 1; y <= q; ++y) {
        for (int x = 1; x <= p; ++x) {
            string s;
            cin >> s;

            for (int z = 1; z <= r; ++z) {
                grid[x][y][z] = (z - 1 < (int)s.size() ? s[z - 1] : '?');
            }
        }
    }

    for (int z = 1; z <= r; ++z)
        for (int x = 1; x <= p; ++x)
            for (int y = 1; y <= q; ++y)
                z_[z][x][y] = (grid[x][y][z] == 'N');

    for (int y = 1; y <= q; ++y)
        for (int x = 1; x <= p; ++x)
            for (int z = 1; z <= r; ++z)
                y_[y][x][z] = (grid[x][y][z] == 'N');

    for (int x = 1; x <= p; ++x)
        for (int y = 1; y <= q; ++y)
            for (int z = 1; z <= r; ++z)
                x_[x][y][z] = (grid[x][y][z] == 'N');

    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            dp[i][j] = 0;

    int ans1 = 0;

    ans1 = max(ans1, calcz(r, p, q));
    ans1 = max(ans1, calcy(q, p, r));
    ans1 = max(ans1, calcx(p, q, r));

    cout << 4LL * ans1;
}