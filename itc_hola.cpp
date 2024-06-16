#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> highway_adj, subway_adj;

void initialize(int n) {
    highway_adj.assign(n, vector<int>());
    subway_adj.assign(n, vector<int>());
}

bool isConnected(const vector<vector<int>>& adj, int n, int u, int v) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == v) {
            return true;
        }
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

bool isBalanced(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected(highway_adj, n, i, j) != isConnected(subway_adj, n, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    initialize(n);
    
    for (int i = 0; i < q; ++i) {
        int xi, ui, vi;
        cin >> xi >> ui >> vi;
        ui -= 1; // Convert to zero-based index
        vi -= 1; // Convert to zero-based index
        
        if (xi == 1) {
            highway_adj[ui].push_back(vi);
            highway_adj[vi].push_back(ui);
        } else {
            subway_adj[ui].push_back(vi);
            subway_adj[vi].push_back(ui);
        }
        
        if (isBalanced(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
