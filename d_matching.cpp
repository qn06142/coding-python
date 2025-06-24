#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;    
vector<int> match_right;    
vector<bool> visited;

bool try_match(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (match_right[v] == -1 || try_match(match_right[v])) {
            match_right[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {});

    for (int i = 0; i < n; i++) {
        for (int j = 0, a; j < n; j++) {
            cin >> a;
            if (a == 1) {
                adj[i].push_back(j);
            }
        }
    }

    match_right.assign(n, -1);
    int max_pairs = 0;

    for (int i = 0; i < n; i++) {
        visited.assign(n, false);
        if (try_match(i)) {
            max_pairs++;
        }
    }

    cout << max_pairs << "\n";
    return 0;
}