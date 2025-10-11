#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,char>>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    const int INF = 1e9;
    vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
    queue<pii> q;

    dist[1][2] = 0;
    q.push({1,2});

    int answer = INF;
    while(!q.empty()){
        auto [u, v] = q.front(); q.pop();
        int d = dist[u][v];

        if(u == v){

            answer = min(answer, d);
        }

        for(auto &e: adj[u]){
            if(e.first == v){

                answer = min(answer, d + 1);
            }
        }

        for(auto &eu: adj[u]){
            int u2 = eu.first;
            char cu = eu.second;
            for(auto &ev: adj[v]){
                int v2 = ev.first;
                char cv = ev.second;
                if(cu == cv && dist[u2][v2] == INF){
                    dist[u2][v2] = d + 2;
                    q.push({u2, v2});
                }
            }
        }
    }

    if(answer == INF) answer = -1;
    cout << answer << "\n";
}