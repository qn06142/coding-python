#include <bits/stdc++.h>

using namespace std;

const int maxn = 405;
int mat[maxn][maxn], pref[maxn][maxn];

bool canFit(int h, int w, int n, int m) {
    for (int i = 1; i <= n - h + 1; ++i) {
        for (int j = 1; j <= m - w + 1; ++j) {
            int x1 = i, y1 = j, x2 = i + h - 1, y2 = j + w - 1;
            int dots = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
            if (dots == h * w) return true;  // Check if all cells in the rectangle are '.'
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // Read the grid and build the mat array
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            mat[i][j] = s[j - 1] == '.' ? 1 : 0;  // 1 for '.', 0 for 'X'
        }
    }

    // Compute prefix sum matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = mat[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    int ans = 0;

    // Iterate over all possible rectangle sizes
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            int perimeter = 2 * (h + w);
            if (canFit(h, w, n, m)) {
                ans = max(ans, perimeter);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
