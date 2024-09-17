#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int x, int y) {

    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || visited[x][y])
        return;

    visited[x][y] = true;

    dfs(x + 1, y); 
    dfs(x - 1, y); 
    dfs(x, y + 1); 
    dfs(x, y - 1); 
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int roomCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                roomCount++; 
            }
        }
    }

    cout << roomCount << endl;

    return 0;
}