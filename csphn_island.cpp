#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    int components;

    DSU(int n) : parent(n), rank(n, 0), components(0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr != yr) {
            if (rank[xr] < rank[yr])
                parent[xr] = yr;
            else if (rank[xr] > rank[yr])
                parent[yr] = xr;
            else {
                parent[yr] = xr;
                ++rank[xr];
            }
            --components;
        }
    }

    void addComponent() {
        ++components;
    }
};

int m, n;
vector<pair<int, pair<int, int>>> cells;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> m >> n;
    cells.resize(m * n);
    int maxHeight = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int h;
            cin >> h;
            cells[i * n + j] = {h, {i, j}};
            maxHeight = max(maxHeight, h);
        }
    }

    sort(cells.rbegin(), cells.rend());  

    DSU dsu(m * n);
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = 0;

    for (int i = 0; i < m * n; ++i) {
        int h = cells[i].first;
        int x = cells[i].second.first;
        int y = cells[i].second.second;
        int index = x * n + y;

        visited[x][y] = true;
        dsu.addComponent();

        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny]) {
                dsu.unite(index, nx * n + ny);
            }
        }
    if (cells[i + 1].first < cells[i].first)
        ans = max(ans, dsu.components);
    }

    cout << ans << endl;
    return 0;
}