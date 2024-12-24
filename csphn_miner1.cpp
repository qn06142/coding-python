#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int m, n, k;
int a[MAXN][MAXN], b[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    q.push({startX, startY});
    visited[startX][startY] = true;
    b[startX][startY] = max(b[startX][startY], a[startX][startY]);

    int steps = 0;
    while (!q.empty() && steps < k) {
        int sz = q.size();
        ++steps;

        while (sz--) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    b[nx][ny] = max(b[nx][ny], a[startX][startY]);
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve() {
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    memset(b, 0, sizeof(b));
    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if(abs(i - x) + abs(j - y) <= k) {
                        b[i][j] = max(b[i][j], a[x][y]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
