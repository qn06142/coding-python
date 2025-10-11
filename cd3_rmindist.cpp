#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    long long a_, b;
    if (!(cin >> m >> n >> a_ >> b)) return 0;
    vector<vector<long long>> a(m, vector<long long>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    if (a_ > b) swap(a_, b); 
    long long base = b - a_; 
    const long long INF = (1LL<<62);
    long long ans = INF;

    for (int r1 = 0; r1 < m; ++r1) {
        vector<long long> col(n, 0);
        for (int r2 = r1; r2 < m; ++r2) {
            for (int j = 0; j < n; ++j) col[j] += a[r2][j];

            vector<long long> pref(n+1, 0);
            for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + col[i-1];

            int idx = 0; 
            for (int r = 1; r <= n; ++r) {
                long long x = pref[r] - a_; 
                long long y = pref[r] - b; 

                while (idx < r && pref[idx] < y) ++idx;

                if (idx < r && pref[idx] <= x) {
                    cout << base << '\n';
                    return 0;
                }

                if (idx > 0) {
                    long long below = y - pref[idx-1]; 
                    if (below < ans) ans = below;
                }
                if (idx < r) {
                    long long above = pref[idx] - x; 
                    if (above < ans) ans = above;
                }
            }
        }
    }

    if (ans == INF) ans = 0; 
    long long ans_ = base + 2 * ans;
    cout << ans_;
}