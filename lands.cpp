#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int mat[205][205];
int pref[205][205];

int get(int x1, int y1, int x2, int y2) {
    int total = pref[x2][y2];
    if (x1 > 1) total -= pref[x1 - 1][y2];
    if (y1 > 1) total -= pref[x2][y1 - 1];
    if (x1 > 1 && y1 > 1) total += pref[x1 - 1][y1 - 1];
    return total;
}

signed main() {
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int x = 1; 
            int curr = 0;
            for (int k = 1; k <= m; k++) { 
                curr = get(i, k, j, x);
                while (x <= m && curr <= t) {
                    x++;
                    if (x <= m) curr = get(i, k, j, x);
                }
                x--; 

                int width = x - k + 1;
                if (get(i, k, j, x) <= t && width > 0) {
                    ans = max(ans, (j - i + 1) * width);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
