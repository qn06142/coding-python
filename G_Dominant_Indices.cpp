#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e6 + 5; 
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], toNode[MAXN], timer_ = 0;
int dep[MAXN];
int subSize[MAXN];

int cnt[MAXN]; 
bool bigchild[MAXN];
long long res[MAXN];

int cur_max = 0;
int best = INT_MAX;

void dfs(int u, int p) {
    tin[u] = ++timer_;
    toNode[timer_] = u;
    subSize[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
        subSize[u] += subSize[v];
    }
    tout[u] = timer_;
}

inline void add(int v) {
    int d = dep[v];
    ++cnt[d];
    if (cnt[d] > cur_max) {
        cur_max = cnt[d];
        best = d;
    } else if (cnt[d] == cur_max) {
        if (d < best) best = d;
    }
}

void addrange(int u) {
    for (int t = tin[u]; t <= tout[u]; ++t) {
        int x = toNode[t];
        if (!bigchild[x]) add(x);
    }
}

void dsu(int u, int p, bool keep) {

    int big = -1;
    int bigsi = 0;
    for (int v : adj[u]) if (v != p) {
        if (subSize[v] > bigsi) { bigsi = subSize[v]; big = v; }
    }

    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);

    if (big != -1) {
        dsu(big, u, true);
        bigchild[big] = true; 
    }

    for (int v : adj[u]) if (v != p && v != big) {
        addrange(v);
    }

    add(u);

    res[u] = best - dep[u];

    if (big != -1) bigchild[big] = false;

    if (!keep) {
        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            cnt[dep[x]] = 0;
        }
        cur_max = 0;
        best = INT_MAX;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer_ = 0;
    dep[1] = 0;
    dfs(1, 0);

    int maxdep = n + 2;
    for (int i = 0; i <= maxdep; ++i) cnt[i] = 0;
    for (int i = 0; i <= n; ++i) bigchild[i] = false;

    cur_max = 0;
    best = INT_MAX;

    dsu(1, 0, false);

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << "\n";
    }
}