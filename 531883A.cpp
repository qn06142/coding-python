#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];
int dist[MAXN + 1];

void bfs(int S) {
    queue<int> q;
    q.push(S);
    dist[S] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // If v is not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    for (int i = 1; i <= N; ++i) {
        dist[i] = -1; // Initialize distances as -1 (not visited)
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(S);

    vector<pair<int, int>> result;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] != -1) {
            result.push_back({dist[i], i});
        }
    }

    sort(result.begin(), result.end());

    for (const auto &p : result) {
        cout << p.second << " " << p.first << endl;
    }

    return 0;
}
