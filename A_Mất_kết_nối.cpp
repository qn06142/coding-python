#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct DSU {
    vector<int> parent, sz;
    int comp;
    struct Change { int u, parent_u, v, sz_v; bool merged; };
    vector<Change> history;

    DSU(int n): parent(n+1), sz(n+1,1), comp(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) {
            history.push_back({0,0,0,0,false});
            return;
        }
        if (sz[a] > sz[b]) swap(a,b);

        history.push_back({a, parent[a], b, sz[b], true});
        parent[a] = b;
        sz[b] += sz[a];
        --comp;
    }

    void rollback() {
        if (history.empty()) return;
        Change ch = history.back();
        history.pop_back();
        if (!ch.merged) return;
        parent[ch.u] = ch.parent_u;
        sz[ch.v] = ch.sz_v;
        ++comp;
    }
};

int N, K;
vector<vector<pii>> segtree;
vector<int> answer;

void add_edge(int idx, int l, int r, int ql, int qr, const pii &e) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        segtree[idx].push_back(e);
        return;
    }
    int mid = (l + r) >> 1;
    add_edge(idx<<1, l, mid, ql, qr, e);
    add_edge(idx<<1|1, mid+1, r, ql, qr, e);
}

void dfs(int idx, int l, int r, DSU &dsu) {
    int before = dsu.history.size();
    for (auto &e : segtree[idx]) {
        dsu.unite(e.first, e.second);
    }
    if (l == r) {
        if (answer[l] == -1) {

            cout << dsu.comp << '\n';
        }
    } else {
        int mid = (l + r) >> 1;
        dfs(idx<<1, l, mid, dsu);
        dfs(idx<<1|1, mid+1, r, dsu);
    }
    while ((int)dsu.history.size() > before) dsu.rollback();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin >> N >> K;
    segtree.assign(4*(K+5), {});
    answer.assign(K+1, 0);

    map<long long,int> add_time;
    vector<pair<int,pii>> queries(K+1);

    for (int t = 1; t <= K; t++) {
        char op;
        cin >> op;
        if (op == '+') {
            int u,v; cin >> u >> v;
            if (u > v) swap(u,v);
            long long key = ((long long)u<<32) | v;
            add_time[key] = t;
            queries[t] = {0,{u,v}};
            answer[t] = 0; 
        } else if (op == '-') {
            int u,v; cin >> u >> v;
            if (u > v) swap(u,v);
            long long key = ((long long)u<<32) | v;
            int t0 = add_time[key];
            add_edge(1,1,K, t0, t-1, {u,v});
            add_time.erase(key);
            queries[t] = {1,{u,v}};
            answer[t] = 0;
        } else if (op == '?') {
            queries[t] = {2,{0,0}};
            answer[t] = -1; 
        }
    }

    for (auto &it : add_time) {
        long long key = it.first;
        int t0 = it.second;
        int u = (int)(key >> 32);
        int v = (int)(key & 0xFFFFFFFF);
        add_edge(1,1,K, t0, K, {u,v});
    }

    DSU dsu(N);
    dfs(1,1,K, dsu);
}