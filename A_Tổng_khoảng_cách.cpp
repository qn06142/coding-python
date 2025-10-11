#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n;
vector<int> adj[maxn];

int tin[maxn], tout[maxn], toNode[maxn], timer = 0;
int dep[maxn];
long long ans = 0;
vector<int> cnt; 

// global aggregates for nodes currently present in cnt
long long cur_cnt = 0;
long long cur_sum_dep = 0;

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

    // process small children and clear them
    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);

    // process big child and keep its data
    if (big != -1) dsu(big, u, true);

    // now merge small children into big's data and compute cross contributions
    for (int v : adj[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            // contribution of pairs (x, all nodes currently in cnt)
            // dist(x,y) = dep[x] + dep[y] - 2*dep[u]
            // sum_y dist(x,y) = cur_cnt * (dep[x] - 2*dep[u]) + cur_sum_dep
            ans += cur_cnt * (long long)(dep[x] - 2 * dep[u]) + cur_sum_dep;
        }
        // then add these nodes into cnt
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            ++cnt[dep[x]];
            ++cur_cnt;
            cur_sum_dep += dep[x];
        }
    }

    // pairs between u and nodes already in cnt (i.e., pairs where one node is u)
    // sum_y dist(u,y) = sum_y (dep[y] - dep[u]) = cur_sum_dep - cur_cnt * dep[u]
    ans += cur_sum_dep - cur_cnt * (long long)dep[u];

    // add u itself
    ++cnt[dep[u]];
    ++cur_cnt;
    cur_sum_dep += dep[u];

    // if not keeping subtree, remove all nodes of this subtree from cnt
    if (!keep) {
        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            --cnt[dep[x]];
            --cur_cnt;
            cur_sum_dep -= dep[x];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep[1] = 0;
    timer = 0;
    dfs(1, 0);

    cnt.assign(n + 1, 0); 
    ans = 0;
    cur_cnt = 0;
    cur_sum_dep = 0;
    dsu(1, 0, false);

    cout << ans << '\n';
    return 0;
}
