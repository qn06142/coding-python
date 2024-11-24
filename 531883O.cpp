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

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, start});  
    dist[start.first][start.second] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (d > dist[x][y]) continue;  

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {

                int new_dist = d + (grid[nx][ny] == '*' ? 1 : 0);

                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    pq.push({new_dist, {nx, ny}});
                }
            }
        }
    }

    cout << dist[end.first][end.second] << endl;

    return 0;
}