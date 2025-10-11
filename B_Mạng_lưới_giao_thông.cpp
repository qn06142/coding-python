#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)4e18;

struct Edge { int u,v; long long w; int idx; bool in_mst=false; };

struct DSU {
    int n; vector<int> p, r;
    DSU(int n=0){ init(n); }
    void init(int n_){ n=n_; p.resize(n+1); r.assign(n+1,0); for(int i=1;i<=n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b); if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a; if(r[a]==r[b]) r[a]++; return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        int u,v; long long w; cin>>u>>v>>w;
        edges[i] = {u,v,w,i,false};
    }

    vector<int> ord(m); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a,int b){
        if(edges[a].w!=edges[b].w) return edges[a].w < edges[b].w;
        return a < b;
    });
    DSU dsu(n); dsu.init(n);
    long long mst_total = 0;
    int used = 0;
    for(int id: ord){
        if(dsu.unite(edges[id].u, edges[id].v)){
            edges[id].in_mst = true;
            mst_total += edges[id].w;
            used++;
        }
    }
    if(used != n-1){
        for(int i=0;i<m;i++) cout << -1 << '\n';
        return 0;
    }

    vector<vector<pair<int,int>>> adj(n+1); 
    vector<long long> mew(m, 0);
    for(int i=0;i<m;i++){
        if(edges[i].in_mst){
            adj[edges[i].u].push_back({edges[i].v, i});
            adj[edges[i].v].push_back({edges[i].u, i});
            mew[i] = edges[i].w;
        }
    }

    int LOG = 1;
    while((1<<LOG) <= n) LOG++;
    vector<int> depth(n+1,0);
    vector<vector<int>> up(LOG, vector<int>(n+1, 0));
    vector<int> parid(n+1, -1);

    function<void(int,int)> dfs0 = [&](int u,int p){
        up[0][u] = p;
        for(auto [v,ei]: adj[u]){
            if(v==p) continue;
            depth[v] = depth[u] + 1;
            parid[v] = ei; 
            dfs0(v,u);
        }
    };
    depth[1]=0; dfs0(1,0);
    for(int k=1;k<LOG;k++){
        for(int v=1; v<=n; v++){
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }
    auto lca = [&](int a,int b){
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a]-depth[b];
        for(int k=0;k<LOG;k++) if(diff>>k & 1) a = up[k][a];
        if(a==b) return a;
        for(int k=LOG-1;k>=0;k--){
            if(up[k][a] != up[k][b]){
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    };

    vector<vector<long long>> ins(n+1), rem(n+1);
    for(int i=0;i<m;i++){
        if(edges[i].in_mst) continue;
        int u = edges[i].u, v = edges[i].v;
        int L = lca(u,v);
        ins[u].push_back(edges[i].w);
        ins[v].push_back(edges[i].w);

        rem[L].push_back(edges[i].w);
        rem[L].push_back(edges[i].w);
    }

    vector<long long> answer(m, -1);
    for(int i=0;i<m;i++) if(!edges[i].in_mst) answer[edges[i].idx] = mst_total;

    function< multiset<long long>* (int,int) > dfs = [&](int u,int p)->multiset<long long>* {
        multiset<long long>* ms = new multiset<long long>();

        for(long long w: ins[u]) ms->insert(w);
        for(auto [v,ei]: adj[u]){
            if(v==p) continue;
            multiset<long long>* child_ms = dfs(v,u);
            if(child_ms->size() > ms->size()) swap(ms, child_ms);

            for(long long val: *child_ms) ms->insert(val);
            delete child_ms;
        }

        for(long long w: rem[u]){
            auto it = ms->find(w);
            if(it != ms->end()) ms->erase(it);

        }

        if(u != 1){
            int ei = parid[u]; 
            if(ms->empty()){
                answer[ei] = -1;
            } else {
                long long best = *ms->begin();
                answer[ei] = mst_total - mew[ei] + best;
            }
        }
        return ms;
    };

    multiset<long long>* root_ms = dfs(1,0);
    delete root_ms;

    for(int i=0;i<m;i++){
        if(answer[i] < 0) cout << -1 << '\n';
        else cout << answer[i] << '\n';
    }
}