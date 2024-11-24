#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include <iostream>
#include <deque>
#include <vector>
#include <climits>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs_minimum_guards(int n, int m, vector<string>& grid) {
    deque<pair<int, int>> dq;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    
    dq.push_front({0, 0});
    dist[0][0] = 0;
    
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int cost = (grid[nx][ny] == grid[x][y]) ? 0 : 1;
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }
    
    return dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        cout << bfs_minimum_guards(n, m, grid) << endl;
    }
    
    return 0;
}
