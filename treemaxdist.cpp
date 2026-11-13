#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;

    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};

const int maxn = 200005;

int par[maxn];
long long sz[maxn];

int find(int u) {
    if (par[u] == u)
        return u;
    return par[u] = find(par[u]);
}

bool unite(int u, int v, long long& pairs) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    pairs = sz[u] * sz[v];
    par[u] = v;
    sz[v] += sz[u];

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<Edge> e(n);

    for (int i = 1; i < n; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e.begin() + 1, e.end());

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    vector<pair<long long,long long>> wc;

    for (int i = 1; i < n; i++) {
        long long cnt = 0;
        unite(e[i].u, e[i].v, cnt);

        if (!wc.empty() && wc.back().first == e[i].w)
            wc.back().second += cnt;
        else
            wc.push_back({e[i].w, cnt});
    }

    int m = wc.size();
    vector<long long> w(m), p(m + 1, 0);

    for (int i = 0; i < m; i++) {
        w[i] = wc[i].first;
        p[i + 1] = p[i] + wc[i].second;
    }

    while (q--) {
        long long l, r;
        cin >> l >> r;

        int x = upper_bound(w.begin(), w.end(), r) - w.begin();
        int y = upper_bound(w.begin(), w.end(), l - 1) - w.begin();

        cout << p[x] - p[y] << (q ? ' ' : '\n');
    }
}