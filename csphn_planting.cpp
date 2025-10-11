#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int tin[maxn], tout[maxn], tonode[maxn];
int dep[maxn], sz[maxn];
int timer = 0;
vector<int> adj[maxn];
map<pair<int, int>, int> weights;
void dfs(int p, int i) {
    tin[i] = ++timer;
    tonode[timer] = i;
    sz[i] = 1;
    for(int v : adj[i]) if (v != p) {
        dep[v] = dep[i] + weights[{i, v}];
        dfs(i, v);
        sz[i] += sz[v];
    }

    tout[i] = timer;
}
void dsu(int u, int p, bool keep) {
    int big = -1;
    int bigsi = 0;
    for (int v : adj[u]) if (v != p) {
        if (sz[v] > bigsi) { bigsi = sz[v]; big = v; }
    }

    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);

}
int main() {
    int n, l;
    cin >> n >> l;
    for(int i = 1; i < n;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weights[{u, v}] = weights[{v, u}] = w;
    }

}