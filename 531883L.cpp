#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};  
const int dy[] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));  
    queue<pair<int, int>> q;
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'G') {
                start = {i, j};
            } else if (grid[i][j] == 'R') {
                end = {i, j};
            }
        }
    }

    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[end.first][end.second] << endl;

    return 0;
}