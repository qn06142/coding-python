#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    const int LIM = 2000000;
    vector<double> visited(m, 0.0);

    std::mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());

    for (int it = 0; it < LIM; ++it) {
        int cur = 1;
        while (cur != n) {
            auto &neis = adj[cur];

            int idx = std::uniform_int_distribution<int>(0, (int)neis.size() - 1)(rng);
            int v = neis[idx].first;
            int eid = neis[idx].second;
            visited[eid] += 1.0;
            cur = v;
        }
    }

    vector<pair<int,double>> edges_;
    edges_.reserve(m);
    for (int i = 0; i < m; ++i) edges_.emplace_back(i, visited[i] / LIM);

    sort(edges_.begin(), edges_.end(),
         [](const pair<int,double>& a, const pair<int,double>& b) {
             if (a.second != b.second) return a.second > b.second;
             return a.first < b.first;
         });

    long double ans = 0.0L;
    for (int i = 0; i < m; ++i) {
        int rank = i + 1;
        long double freq = edges_[i].second;
        ans += freq * rank;
    }

    cout.setf(std::ios::fixed); 
    cout << setprecision(3) << (double)ans << "\n";
}