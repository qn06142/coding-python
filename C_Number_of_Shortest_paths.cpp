#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    adj.reserve(n);
    for(int i = 0; i < m; i++){
        int A, B;
        cin >> A >> B;
        --A; --B;               
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    const int INF = 1e9;
    vector<int> dist(n, INF);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if(dist[n-1] == INF){
        cout << 0 << "\n";
        return 0;
    }

    vector<long long> ans(n, 0);
    ans[0] = 1;

    int D = dist[n-1];
    vector<vector<int>> by_dist(D+1);
    for(int v = 0; v < n; v++){
        if(dist[v] <= D)
            by_dist[dist[v]].push_back(v);
    }

    for(int d = 0; d < D; d++){
        for(int u : by_dist[d]){
            long long ways = ans[u];
            if(!ways) continue;
            for(int v : adj[u]){
                if(dist[v] == d + 1){
                    ans[v] = (ans[v] + ways) % MOD;
                }
            }
        }
    }

    cout << ans[n-1] << "\n";
}