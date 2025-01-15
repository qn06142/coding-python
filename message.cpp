#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN], rev_adj[MAXN];
vector<int> component[MAXN];
int scc_id[MAXN], in_degree[MAXN];
bool visited[MAXN];
stack<int> st;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, int id) {
    visited[u] = true;
    scc_id[u] = id;
    for (int v : rev_adj[u]) {
        if (!visited[v]) dfs2(v, id);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }

    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs1(i);
    }

    fill(visited, visited + n + 1, false);
    int scc_count = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            ++scc_count;
            dfs2(u, scc_count);
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                in_degree[scc_id[v]]++;
            }
        }
    }

    int source_count = 0;
    for (int i = 1; i <= scc_count; ++i) {
        if (in_degree[i] == 0) source_count++;
    }

    cout << source_count << '\n';
    return 0;
}