#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int lg = 20;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &o) const {
        return w > o.w;
    }
} e[maxn];

struct Node {
    int v, w;
};

vector<Node> g[maxn];

int p[maxn];

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

bool Join(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return 0;

    p[u] = v;
    return 1;
}

int dep[maxn];
int up[maxn][lg];
int mx[maxn][lg];

void dfs(int u, int par, int w) {
    up[u][0] = par;
    mx[u][0] = w;

    for (int i = 1; i < lg; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[up[u][i - 1]][i - 1]);
    }

    for (auto x : g[u]) {
        if (x.v == par) continue;
        dep[x.v] = dep[u] + 1;
        dfs(x.v, u, x.w);
    }
}

int query(int u, int v) {
    int res = 0;

    if (dep[u] < dep[v]) swap(u, v);

    int d = dep[u] - dep[v];

    for (int i = lg - 1; i >= 0; i--)
        if (d & (1 << i)) {
            res = max(res, mx[u][i]);
            u = up[u][i];
        }

    if (u == v) return res;

    for (int i = lg - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }

    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);

    return res;
}

vector<Edge> ext;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e + 1, e + m + 1);

    for (int i = 1; i <= m; i++) {
        if (Join(e[i].u, e[i].v)) {
            g[e[i].u].push_back({e[i].v, e[i].w});
            g[e[i].v].push_back({e[i].u, e[i].w});
        } else {
            ext.push_back(e[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dep[i]) {
            dep[i] = 1;
            dfs(i, i, 0);
        }
    }

    int ans = 0;

    for (auto x : ext)
        ans = max(ans, x.w + query(x.u, x.v));

    cout << ans;
}
