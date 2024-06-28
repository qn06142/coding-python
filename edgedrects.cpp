// Make the best become better
// No room for laziness
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18;

int n, m;
vector<vector<int>> a, lf, rg, up, down, val1, val2;

struct cmp {
    bool operator ()(pair<int, int> p, pair<int, int> q) const {
        return p.fi + val1[p.fi][p.se] > q.fi + val1[q.fi][q.se];
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> S[maxN];
set<int> s[maxN];

void reset(vector<vector<int>>& a) {
    a.resize(n + 5);
    for (int i = 0; i <= n + 1; i++) {
        a[i].resize(m + 5);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    reset(a);
    reset(lf);
    reset(rg);
    reset(up);
    reset(down);
    reset(val1);
    reset(val2);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Calculate left and up values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) {
                lf[i][j] = up[i][j] = 0;
                continue;
            }
            lf[i][j] = lf[i][j - 1] + a[i][j];
            up[i][j] = up[i - 1][j] + a[i][j];
        }
    }

    // Calculate right and down values
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (!a[i][j]) {
                rg[i][j] = down[i][j] = 0;
                continue;
            }
            rg[i][j] = rg[i][j + 1] + a[i][j];
            down[i][j] = down[i + 1][j] + a[i][j];
        }
    }

    // Calculate val1 and val2 values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            val1[i][j] = min(lf[i][j], down[i][j]);
            val2[i][j] = min(rg[i][j], up[i][j]);
        }
    }

    int res = 0;

    // Process each cell
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num = i + j;
            s[num].insert(i);
            S[num].push({i, j});

            // Remove invalid elements from the priority queue
            while (!S[num].empty()) {
                pair<int, int> p = S[num].top();
                if (p.fi + val1[p.fi][p.se] - 1 >= i) break;
                S[num].pop();
                s[num].erase(p.fi);
            }

            int tmp = val2[i][j];
            auto it = s[num].lower_bound(i - tmp + 1);

            // Update the result
            if (it != s[num].end()) {
                res = max(res, (i - *it + 1) * (i - *it + 1));
            }
        }
    }

    cout << res;

    return 0;
}
