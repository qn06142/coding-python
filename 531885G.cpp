#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
vector<int> graph[MAX_N + 1];
int parent[MAX_N + 1];
bool visited[MAX_N + 1];
vector<int> cycle;
bool foundCycle = false;

void dfs(int u, int par) {
    visited[u] = true;
    parent[u] = par;

    for (int v : graph[u]) {
        if (v == par) continue; 
        if (visited[v]) {

            if (!foundCycle) {
                foundCycle = true;

                cycle.push_back(v);
                for (int x = u; x != v; x = parent[x]) {
                    cycle.push_back(x);
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
            }
            return;
        }
        parent[v] = u;
        dfs(v, u);
        if (foundCycle) return;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(visited, visited + n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
            if (foundCycle) break;
        }
    }

    if (foundCycle) {
        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}