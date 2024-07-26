#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];
int dist[MAXN + 1];
int parent[MAXN + 1];

void bfs(int start, int n) {
    fill(dist, dist + n + 1, -1);
    fill(parent, parent + n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        sort(adj[u].begin(), adj[u].end());

        for (int v : adj[u]) {
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

vector<int> get_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bfs(s, N);

    vector<int> path = get_path(s, t);

    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}