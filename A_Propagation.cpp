#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, Q;
    if(!(cin >> N >> M >> Q)) return 0;
    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> basev(N+1);
    for(int i=1;i<=N;i++) basev[i] = i;

    vector<int> queries(Q);
    for(int i=0;i<Q;i++) cin >> queries[i];

    int B = max(1, (int) sqrt(max(1, M)));

    vector<char> heavy(N+1, 0);
    for(int v=1; v<=N; ++v) if((int)adj[v].size() > B) heavy[v] = 1;

    vector<vector<int>> heavy_neigh(N+1);
    for(int v=1; v<=N; ++v){
        for(int u: adj[v]) if(heavy[u]) heavy_neigh[v].push_back(u);
    }

    vector<int> base_time(N+1, 0);
    vector<int> heavy_time(N+1, 0), heavy_val(N+1, 0);

    for(int v=1; v<=N; ++v) if(heavy[v]) heavy_val[v] = basev[v];

    int now = 1;
    auto read_val = [&](int v)->int{
        int res = basev[v];
        int t = base_time[v];
        for(int h: heavy_neigh[v]){
            if(heavy_time[h] > t){
                t = heavy_time[h];
                res = heavy_val[h];
            }
        }
        return res;
    };

    for(int xi: queries){
        int X = read_val(xi);
        if(heavy[xi]){
            heavy_val[xi] = X;
            heavy_time[xi] = now;
        } else {
            for(int nb: adj[xi]){
                basev[nb] = X;
                base_time[nb] = now;
            }
        }
        ++now;
    }

    for(int i=1;i<=N;i++){
        cout << read_val(i) << ' ';
    }
}