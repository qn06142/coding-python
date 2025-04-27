#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, s, t;
vector<vector<int>> adj;    
vector<bool> visited;       
vector<int> path;           
bool found = false;         

void dfs(int u) {
    path.push_back(u);
    visited[u] = true;

    if(u == t) {
        for (int v : path)
            cout << v << " ";
        cout << "\n";
        found = true;
        return;
    }

    for(int v : adj[u]) {
        if(!visited[v] && !found) {
            dfs(v);
        }
    }

    if(!found) {
        visited[u] = false;
        path.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> s >> t;

    adj.resize(N + 1);
    visited.assign(N + 1, false);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(s);

    return 0;
}