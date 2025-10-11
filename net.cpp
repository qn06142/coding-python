#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100000;
int N, M, K, L;
vector<int> adj[MAXN+1];
bool is_a[MAXN+1], is_b[MAXN+1];
int total_a = 0, total_b = 0;

int timer = 0;
int disc[MAXN+1], low[MAXN+1];
bool visited[MAXN+1];

int sub_a[MAXN+1], sub_b[MAXN+1];
ll answer = 0;

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    sub_a[u] = is_a[u];
    sub_b[u] = is_b[u];

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (!visited[v]) {
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            sub_a[u] += sub_a[v];
            sub_b[u] += sub_b[v];

            if (low[v] > disc[u]) {
                int a_v = sub_a[v];
                int b_v = sub_b[v];
                int a_other = total_a - a_v;
                int b_other = total_b - b_v;
                if (a_v == 0 || a_other == 0 || b_v == 0 || b_other == 0) {
                    ++answer;
                }
            }
        } else {

            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> L;
    for (int i = 0, x; i < K; ++i) {
        cin >> x;
        if (!is_a[x]) {
            is_a[x] = true;
            ++total_a;
        }
    }
    for (int i = 0, x; i < L; ++i) {
        cin >> x;
        if (!is_b[x]) {
            is_b[x] = true;
            ++total_b;
        }
    }
    for (int i = 0, u, v; i < M; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    cout << answer << "\n";
    return 0;
}