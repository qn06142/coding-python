#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n+1), r(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> close_order(N+1);
    for(int i = 1; i <= N; i++){
        cin >> close_order[i];
    }

    DSU dsu(N);
    vector<bool> active(N+1,false);
    vector<bool> ans_add(N+2,false);

    int components = 0;

    for(int k = N; k >= 1; k--){
        int u = close_order[k];
        active[u] = true;
        components++;
        for(int v: adj[u]){
            if(active[v]){
                if(dsu.unite(u, v))
                    components--;
            }
        }

        ans_add[k] = (components == 1);
    }

    for(int i = 1; i <= N; i++){
        bool ok = ans_add[i];
        cout << (ok ? "YES\n" : "NO\n");
    }
}