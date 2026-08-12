#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxm = 200005;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &o) const {
        return w > o.w;
    }
} e[maxm];

struct Node {
    int v, w;
};

vector<Node> g[maxn];

int p[maxn];
int n, m, q;

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

int ans;

bool dfs(int u, int t, int mn, int par) {
    if (u == t) {
        ans = mn;
        return 1;
    }

    for (auto x : g[u]) {
        if (x.v == par) continue;
        if (dfs(x.v, t, min(mn, x.w), u))
            return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e + 1, e + m + 1);

    int cnt = 0;
    for (int i = 1; i <= m && cnt < n - 1; i++) {
        if (!Join(e[i].u, e[i].v)) continue;

        g[e[i].u].push_back({e[i].v, e[i].w});
        g[e[i].v].push_back({e[i].u, e[i].w});
        cnt++;
    }

    cin >> q;

    while (q--) {
        int s, t;
        cin >> s >> t;

        ans = 0;
        dfs(s, t, 2000000000, 0);

        cout << ans << '\n';
    }
}