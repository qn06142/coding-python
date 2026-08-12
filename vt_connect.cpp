#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    vector<vector<pair<int, long long>>> tree(n + 1);
    long long mst_weight = 0;

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
        }
    }

    const int LOG = 20;
    vector<vector<int>> up(LOG, vector<int>(n + 1, 0));
    vector<vector<long long>> mx(LOG, vector<long long>(n + 1, 0));
    vector<int> depth(n + 1, 0);
    vector<int> visited(n + 1, 0);

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [to, w] : tree[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                depth[to] = depth[v] + 1;
                up[0][to] = v;
                mx[0][to] = w;
                q.push(to);
            }
        }
    }

    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            int p = up[k - 1][v];
            up[k][v] = up[k - 1][p];
            mx[k][v] = max(mx[k - 1][v], mx[k - 1][p]);
        }
    }

    auto max_on_path = [&](int u, int v) -> long long {
        long long res = 0;
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG - 1; k >= 0; --k) {
            if ((depth[u] - depth[v]) & (1 << k)) {
                res = max(res, mx[k][u]);
                u = up[k][u];
            }
        }

        if (u == v) return res;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                res = max({res, mx[k][u], mx[k][v]});
                u = up[k][u];
                v = up[k][v];
            }
        }

        return max({res, mx[0][u], mx[0][v]});
    };

    vector<long long> ans(m);
    for (const auto &e : edges) {
        if (e.id >= 0) {
            // We store the answer after the whole MST is built.
        }
    }

    // Rebuild answers in the original order.
    vector<int> in_mst(m, 0);
    DSU dsu2(n);
    for (const auto &e : edges) {
        if (dsu2.unite(e.u, e.v)) {
            in_mst[e.id] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        const Edge &e = edges[i];
        if (in_mst[e.id]) {
            ans[e.id] = mst_weight;
        } else {
            ans[e.id] = mst_weight + e.w - max_on_path(e.u, e.v);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
