#include <iostream>
#include <vector>
using namespace std;

int m, n, k;
vector<string> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> empty_cells;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    visited[x][y] = true;
    empty_cells.push_back({x, y});
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> m >> n >> k;
    grid.resize(m);
    visited.assign(m, vector<bool>(n, false));

    int total_empty = 0;
    for (int i = 0; i < m; ++i) {
        cin >> grid[i];
        for (char c : grid[i]) {
            if (c == '.') ++total_empty;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                break;
            }
        }
        if (!empty_cells.empty()) break;
    }

    for (int i = 0; i < k; ++i) {
        auto [x, y] = empty_cells.back();
        empty_cells.pop_back();
        grid[x][y] = 'X';
    }

    for (int i = 0; i < m; ++i) {
        cout << grid[i] << endl;
    }

    return 0;
}