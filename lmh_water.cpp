#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int height, row, col;
    Cell(int h, int r, int c) : height(h), row(r), col(c) {}
    bool operator>(const Cell& other) const {
        return height > other.height;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> heights(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> heights[i][j];

    if (m <= 2 || n <= 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                pq.emplace(heights[i][j], i, j);
                visited[i][j] = true;
            }

    long long ans = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        for (auto [dr, dc] : directions) {
            int nr = current.row + dr;
            int nc = current.col + dc;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                visited[nr][nc] = true;
                int neigh = heights[nr][nc];

                if (current.height > neigh)
                    ans += current.height - neigh;

                int new_height = max(current.height, neigh);
                pq.emplace(new_height, nr, nc);
            }
        }
    }

    cout << ans;
    return 0;
}
