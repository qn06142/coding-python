#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    ll w;
    int company; 
};

struct union_find {
    int n;
    vector<int> parent, rankv;
    union_find(int _n): n(_n), parent(n+1), rankv(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (rankv[rx] < rankv[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rankv[rx] == rankv[ry]) rankv[rx]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<Edge> edges;
    edges.reserve(m);
    vector<ll> weights_a, weights_b;

    for (int i = 0; i < m; i++) {
        int c; ll u, v, w;
        cin >> c >> u >> v >> w;
        edges.push_back({(int)u, (int)v, w, c});
        if (c == 1) weights_a.push_back(w);
        else          weights_b.push_back(w);
    }

    sort(weights_a.begin(), weights_a.end());
    weights_a.erase(unique(weights_a.begin(), weights_a.end()), weights_a.end());
    sort(weights_b.begin(), weights_b.end());
    weights_b.erase(unique(weights_b.begin(), weights_b.end()), weights_b.end());

    const ll INF = (ll)4e18;
    ll best = INF;
    int a_lo = 0, a_hi = (int)weights_a.size() - 1;

    auto is_connected = [&](ll a_th, ll b_th) {
        union_find uf(n);
        for (auto &e: edges) {
            if ((e.company == 1 && e.w <= a_th) ||
                (e.company == 2 && e.w <= b_th)) {
                uf.unite(e.u, e.v);
            }
        }
        return uf.find(s) == uf.find(t);
    };

    while (a_lo <= a_hi) {
        int a_mid = (a_lo + a_hi) / 2;
        ll a_th = weights_a[a_mid];

        int b_lo = 0, b_hi = (int)weights_b.size() - 1;
        ll b_ans = INF;
        while (b_lo <= b_hi) {
            int b_mid = (b_lo + b_hi) / 2;
            ll b_th = weights_b[b_mid];
            if (is_connected(a_th, b_th)) {
                b_ans = b_th;
                b_hi = b_mid - 1;
            } else {
                b_lo = b_mid + 1;
            }
        }

        if (b_ans == INF) {

            a_lo = a_mid + 1;
        } else {
            best = min(best, a_th + b_ans);

            a_hi = a_mid - 1;
        }
    }

    cout << best << '\n';
    return 0;
}