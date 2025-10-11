#include <bits/stdc++.h>
using namespace std;

void dfs1(int v, const vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs1(u, adj, vis, order);
    order.push_back(v);
}

void dfs2(int v, const vector<vector<int>>& adj_rev, vector<bool>& vis, vector<int>& comp, int cid) {
    vis[v] = true;
    comp[v] = cid;
    for (int u : adj_rev[v])
        if (!vis[u])
            dfs2(u, adj_rev, vis, comp, cid);
}

tuple<int, vector<int>, vector<vector<int>>>
condense_graph(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> order; order.reserve(n);

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i, adj, vis, order);

    vector<vector<int>> adj_rev(n);
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            adj_rev[v].push_back(u);

    fill(vis.begin(), vis.end(), false);
    vector<int> comp(n, -1);
    int scc_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (!vis[v]) {
            dfs2(v, adj_rev, vis, comp, scc_cnt);
            ++scc_cnt;
        }
    }

    vector<unordered_set<int>> tmp(scc_cnt);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            int cu = comp[u], cv = comp[v];
            if (cu != cv)
                tmp[cu].insert(cv);
        }
    }

    vector<vector<int>> condensed(scc_cnt);
    for (int i = 0; i < scc_cnt; ++i)
        condensed[i].assign(tmp[i].begin(), tmp[i].end());

    return {scc_cnt, comp, condensed};
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    vector<int> comp;
    vector<vector<int>> dag;
    int C;
    tie(C, comp, dag) = condense_graph(adj);

    vector<long long> scc_coins(C, 0);
    for (int i = 0; i < n; i++) {
        scc_coins[comp[i]] += coins[i];
    }

    vector<int> indeg(C, 0);
    for (int u = 0; u < C; u++)
        for (int v : dag[u])
            indeg[v]++;

    queue<int> q;
    for (int i = 0; i < C; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;
    topo.reserve(C);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : dag[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    vector<long long> dp(C, 0);
    long long ans = 0;
    for (int u : topo) {

        dp[u] += scc_coins[u];
        ans = max(ans, dp[u]);
        for (int v : dag[u]) {
            dp[v] = max(dp[v], dp[u]);
        }
    }

    cout << ans << "\n";
}

int main(){
    solve();
}