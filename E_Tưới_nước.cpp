#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

const int MAXN = 300;
int parent[MAXN + 1], rank_[MAXN + 1];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank_[rootX] > rank_[rootY]) {
            parent[rootY] = rootX;
        } else if (rank_[rootX] < rank_[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank_[rootX]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> w(n + 1);
    vector<Edge> edges;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        edges.push_back({0, i, w[i]});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int pij;
            cin >> pij;
            if (i < j) {
                edges.push_back({i, j, pij});
            }
        }
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    int mst_cost = 0, edges_used = 0;
    for (const auto &edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);
            mst_cost += edge.cost;
            edges_used++;
            if (edges_used == n) break;
        }
    }

    cout << mst_cost << '\n';
    return 0;
}
