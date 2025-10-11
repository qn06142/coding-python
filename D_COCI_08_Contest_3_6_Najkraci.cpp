#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9 + 7;

struct Edge { int to, w, idx; };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> g(N+1);
    vector<int> from(M), to(M), weight(M);
    for(int i = 0; i < M; i++){
        cin >> from[i] >> to[i] >> weight[i];
        g[from[i]].push_back({to[i], weight[i], i});
    }

    vector<long long> ans(M, 0);

    vector<long long> dist(N+1), ways(N+1), dp_out(N+1);
    vector<bool> seen(N+1);
    vector<vector<int>> tight_adj(N+1);

    for(int s = 1; s <= N; s++){

        fill(dist.begin(), dist.end(), LLONG_MAX);
        fill(ways.begin(), ways.end(), 0);
        fill(seen.begin(), seen.end(), false);
        dist[s] = 0;
        ways[s] = 1;
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<>> pq;
        pq.push({0, s});

        while(!pq.empty()){
            auto [d,u] = pq.top(); 
            pq.pop();
            if(seen[u]) continue;
            seen[u] = true;
            for(auto &e : g[u]){
                int v = e.to;
                long long nd = d + e.w;
                if(nd < dist[v]){
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                }
                else if(nd == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        for(int u = 1; u <= N; u++){
            tight_adj[u].clear();
        }
        for(int i = 0; i < M; i++){
            int u = from[i], v = to[i], w = weight[i];
            if(dist[u] != LLONG_MAX
               && dist[u] + w == dist[v]){
                tight_adj[u].push_back(v);
            }
        }

        vector<int> order(N);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(),
             [&](int a,int b){ return dist[a] > dist[b]; });

        for(int v : order){

            dp_out[v] = 1;
            for(int w : tight_adj[v]){
                dp_out[v] = (dp_out[v] + dp_out[w]) % MOD;
            }
        }

        for(int i = 0; i < M; i++){
            int u = from[i], v = to[i], w = weight[i];
            if(dist[u] != LLONG_MAX
               && dist[u] + w == dist[v]){
                ans[i] = (ans[i] + ways[u] * dp_out[v]) % MOD;
            }
        }
    }

    for(long long x : ans)
        cout << x << "\n";
}