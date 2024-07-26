#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 20000;
vector<int> adj[MAXN + 1];
int dist[MAXN + 1];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        dist[i] = -1; 
    }

    bfs(1); 

    for (int i = 0; i < Q; ++i) {
        int p;
        cin >> p;
        cout << dist[p] << endl; 
    }

    return 0;
}