#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500005;
const int LOGN = 20;

struct Edge {
    int u, v, l, a;

    bool operator<(const Edge& o) const {
        return a > o.a;
    }
};

struct E {
    int to, w;
};

int n, m;
vector<E> adj[MAXN];
Edge e[MAXN];

int d[MAXN];

int par[MAXN * 2];
int val[MAXN * 2];
int mn[MAXN * 2];

vector<int> tree[MAXN * 2];

int up[MAXN * 2][LOGN];

int find_set(int u) {
    return par[u] == u ? u : par[u] = find_set(par[u]);
}

void dfs(int u, int p) {
    up[u][0] = p;

    for (int i = 1; i < LOGN; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : tree[u])
        dfs(v, u);
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].l >> e[i].a;

        adj[e[i].u].push_back({e[i].v, e[i].l});
        adj[e[i].v].push_back({e[i].u, e[i].l});
    }

    memset(d, 0x3f, sizeof d);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du != d[u])
            continue;

        for (auto x : adj[u]) {
            if (d[x.to] > du + x.w) {
                d[x.to] = du + x.w;
                pq.push({d[x.to], x.to});
            }
        }
    }

    sort(e, e + m);

    int tot = n;

    for (int i = 1; i <= 2 * n; i++) {
        par[i] = i;
        val[i] = 0;
        mn[i] = INF;
        tree[i].clear();
    }

    for (int i = 1; i <= n; i++)
        mn[i] = d[i];

    for (int i = 0; i < m; i++) {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);

        if (u != v) {
            ++tot;

            val[tot] = e[i].a;
            par[u] = tot;
            par[v] = tot;
            par[tot] = tot;

            tree[tot].push_back(u);
            tree[tot].push_back(v);

            mn[tot] = min(mn[u], mn[v]);
        }
    }

    for (int i = 1; i <= tot; i++) {
        if (par[i] == i)
            dfs(i, 0);
    }

    int Q, K, S;
    cin >> Q >> K >> S;

    int last = 0;

    while (Q--) {
        int v, p;
        cin >> v >> p;

        v = (v + K * last - 1) % n + 1;
        p = (p + K * last) % (S + 1);

        int u = v;

        for (int i = LOGN - 1; i >= 0; i--) {
            if (up[u][i] && val[up[u][i]] > p)
                u = up[u][i];
        }

        last = mn[u];
        cout << last << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}