#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1010000;
const int MAXN = 100005;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> f(MAXN);
    vector<vector<long long>> g(MAXN);

    for (int C = 1; C < n; ++C) {
        f[C].push_back(0); // f(C, 0) = 0
        for (int k = 1; (k + 1) * C < n - 1; ++k) {
            f[C].push_back(f[C].back() + a[k * C]); // f(C, k) = f(C, k - 1) + a[k * C]
        }
    }

    for (int C = 1; C < n; ++C) {
        g[C].push_back(0); // g(C, 0) = 0
        for (int k = 1; (k + 1) * C < n - 1; ++k) {
            g[C].push_back(g[C].back() + a[n - 1 - k * C]); // g(C, k) = g(C, k - 1) + a[n - 1 - k * C]
        }
    }

    long long max_score = -INF;
    for (int C = 1; C < n; ++C) {
        for (int k = 0; k < f[C].size() && k < g[C].size(); ++k) {
            max_score = max(max_score, f[C][k] + g[C][k]);
        }
    }

    cout << max_score << endl;
    return 0;
}
