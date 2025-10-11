#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n, k;
vector<int> adj[maxn];

int tin[maxn], tout[maxn], toNode[maxn], timer = 0;
int dep[maxn];
long long ans = 0;
vector<int> cnt; 

void dfs(int u = 1, int p = 0) {
    tin[u] = ++timer;
    toNode[timer] = u;
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    tout[u] = timer;
}

inline int subsz(int u) { return tout[u] - tin[u] + 1; }

void dsu(int u = 1, int p = 0, bool keep = false) {

    int big = -1, bestSize = 0;
    for (int v : adj[u]) if (v != p) {
        int s = subsz(v);
        if (s > bestSize) { bestSize = s; big = v; }
    }

    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);

    if (big != -1) dsu(big, u, true);

    for (int v : adj[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];

            int need = k - dep[x] + 2 * dep[u];
            if (need >= 0 && need < (int)cnt.size()) ans += cnt[need];
        }

        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            ++cnt[dep[x]];
        }
    }

    if (k + dep[u] >= 0 && k + dep[u] < (int)cnt.size()) ans += cnt[k + dep[u]];

    ++cnt[dep[u]];

    if (!keep) {
        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            --cnt[dep[x]];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 0) {
        cout << n << '\n';
        return 0;
    }

    dep[1] = 0;
    timer = 0;
    dfs(1, 0);

    cnt.assign(n + 1, 0); 
    ans = 0;
    dsu(1, 0, false);

    cout << ans << '\n';
}