#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MaXn = 250000;
int n, Q;
vector<int> a;
vector<pair<int,int>> queries;

vector<vector<int>> ys;
vector<vector<int>> bit;

void add(int pos, int val, int delta) {
    for (int i = pos; i <= n; i += i & -i) {
        vector<int> &vec = ys[i];
        int idx = int(lower_bound(vec.begin(), vec.end(), val) - vec.begin()) + 1;
        for (int j = idx; j < (int)bit[i].size(); j += j & -j)
            bit[i][j] += delta;
    }
}

int sum_(const vector<int> &f, int idx) {
    int s = 0;
    for (int i = idx; i > 0; i -= i & -i)
        s += f[i];
    return s;
}

int query(int pos, int val) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        const vector<int> &vec = ys[i];
        int idx = int(upper_bound(vec.begin(), vec.end(), val) - vec.begin());
        if (idx > 0)
            res += sum_(bit[i], idx);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    cin >> Q;
    queries.resize(Q);
    for (int i = 0; i < Q; ++i) cin >> queries[i].first >> queries[i].second;

    ys.assign(n + 1, {});

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += j & -j)
            ys[j].push_back(a[i]);
    }
    for (auto &q : queries) {
        int x = q.first, y = q.second;
        for (int j = x; j <= n; j += j & -j)
            ys[j].push_back(y);
    }

    bit.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        vector<int> &v = ys[i];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        bit[i].assign(v.size() + 1, 0);
    }

    for (int i = 1; i <= n; ++i)
        add(i, a[i], +1);

    ll inv = 0;
    for (int i = 1; i <= n; ++i) {
        int leq = query(i - 1, a[i]);        
        ll lg = (i - 1) - leq;
        inv += lg;
    }

    for (int qi = 0; qi < Q; ++qi) {
        int x = queries[qi].first;
        int y = queries[qi].second;
        int old = a[x];

        int leftLeq_old = query(x - 1, old);
        ll lg_old = (x - 1) - leftLeq_old;
        int rl_old = query(n, old - 1) - query(x, old - 1);

        add(x, old, -1);

        int leftLeq_new = query(x - 1, y);
        ll lg_new = (x - 1) - leftLeq_new;
        int rl_new = query(n, y - 1) - query(x, y - 1);

        add(x, y, +1);
        a[x] = y;

        inv += (lg_new + rl_new)
             - (lg_old + rl_old);

        cout << inv << '\n';
    }
}