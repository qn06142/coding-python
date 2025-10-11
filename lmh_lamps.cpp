#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> adj;
    vector<int> dist, pairU, pairV;

    HopcroftKarp(int _nL, int _nR)
      : nL(_nL), nR(_nR),
        adj(nL+1),
        dist(nL+1),
        pairU(nL+1, 0),
        pairV(nR+1, 0)
    {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for(int u = 1; u <= nL; ++u) {
            if(pairU[u] == 0) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        bool reachedFree = false;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: adj[u]) {
                if(pairV[v] == 0) {
                    reachedFree = true;
                } else if(dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
        return reachedFree;
    }

    bool dfs(int u) {
        for(int v: adj[u]) {
            if(pairV[v] == 0
               || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = INT_MAX;
        return false;
    }

    int maximum_matching() {
        int result = 0;
        while(bfs()) {
            for(int u = 1; u <= nL; ++u) {
                if(pairU[u] == 0 && dfs(u))
                    ++result;
            }
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n,p;
    cin >> m >> n >> p;

    vector<pair<int,int>> edges(p);
    vector<int> degR(m+1,0), degC(n+1,0);

    vector<vector<int>> idx(m+1, vector<int>(n+1, -1));
    for(int i = 0; i < p; i++){
        int r,c;
        cin >> r >> c;
        edges[i] = {r,c};
        degR[r]++; degC[c]++;
        idx[r][c] = i;
    }

    int K = 0;
    for(int i=1;i<=m;i++) K = max(K, degR[i]);
    for(int i=1;i<=n;i++) K = max(K, degC[i]);

    vector<int> color(p, 0);
    vector<int> uncol; 
    uncol.reserve(p);
    for(int i=0;i<p;i++) uncol.push_back(i);

    for(int col = 1; col <= K && !uncol.empty(); col++){
        HopcroftKarp hk(m, n);

        for(int e : uncol){
            auto [r,c] = edges[e];
            hk.add_edge(r, c);
        }

        hk.maximum_matching();

        vector<int> next_uncol;
        next_uncol.reserve(uncol.size());

        for(int r = 1; r <= m; r++){
            int c = hk.pairU[r];
            if(c != 0){
                int e = idx[r][c];
                color[e] = col;
            }
        }

        for(int e : uncol){
            if(color[e] == 0)
                next_uncol.push_back(e);
        }
        uncol.swap(next_uncol);
    }

    cout << K << "\n";
    for(int i = 0; i < p; i++){
        cout << color[i] << (i+1<p ? ' ' : '\n');
    }
    return 0;
}