#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, comp_size;
    int com;
    int sz;

    DSU(int _n): n(_n) {
        parent.resize(n+1);
        comp_size.resize(n+1, 1);
        for (int i = 1; i <= n; i++) 
            parent[i] = i;
        com = n;
        sz = 1;
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;

        if (comp_size[ra] < comp_size[rb]) 
            swap(ra, rb);
        parent[rb] = ra;
        comp_size[ra] += comp_size[rb];
        com--;
        sz = max(sz, comp_size[ra]);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);

        cout << dsu.com << " " << dsu.sz << "\n";
    }
}