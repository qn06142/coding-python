#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000;

int parent[MAXN + 1];
int rank_[MAXN + 1];

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        if (find_set(u) != find_set(v)) {
            cout << "Y\n";
            union_sets(u, v);
        } else {
            cout << "N\n";
        }
    }

    return 0;
}