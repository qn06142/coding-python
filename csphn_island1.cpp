#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y, int waterLevel) {
    return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] > waterLevel;
}

void bfs(int startX, int startY, int waterLevel) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            
            if (isValid(newX, newY, waterLevel)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m >> n;
    grid.assign(m, vector<int>(n));
    set<int> uniqueHeights;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            uniqueHeights.insert(grid[i][j]);
        }
    }
    
    int maxIslands = 0;
    
    for (int waterLevel : uniqueHeights) {
        visited.assign(m, vector<bool>(n, false));
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > waterLevel && !visited[i][j]) {
                    islands++;
                    bfs(i, j, waterLevel);
                }
            }
        }
        
        maxIslands = max(maxIslands, islands);
    }
    
    cout << maxIslands << "\n";
    return 0;
}
