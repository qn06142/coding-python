#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int n, int m, const vector<vector<pair<int, int>>>& adj, int limit) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n) {
            return true;
        }

        for (pair<int, int> neighbor : adj[node]) {
            if (!visited[neighbor.first] and neighbor.second <= limit) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    return false;
}

int calc(int n, int m, const vector<vector<pair<int, int>>>& adj) {
    int left = 1, right = m;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(n, m, adj, mid)) {
            result = mid; 
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<vector<pair<int, int>>> adj;
    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        adj[edges[i].first].push_back({edges[i].second, i + 1});
    }
    cout << calc(n, m, adj) << "\n";
    return 0;
}