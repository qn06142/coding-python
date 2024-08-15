#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

vector<int> dijkstra(int N, int start, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(N+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> boxes(K);
    for (int i = 0; i < K; ++i) {
        cin >> boxes[i];
    }

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back({u, 1});  
    }

    vector<int> dist = dijkstra(N, 1, adj);
    int result = 0;

    for (int i = 0; i < K; ++i) {
        if (dist[boxes[i]] == INF) {
            cout << -1 << endl;  
            return 0;
        }
        result += dist[boxes[i]];
    }

    cout << result << endl;

    return 0;
}