#include <iostream>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

struct Node {
    int x, y, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m + 1, vector<int>(n + 1));
    vector<vector<int>> dis(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    deque<Node> dq;
    dq.push_back({1, 1, mat[1][1]});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        Node cur = dq.front();
        dq.pop_front();

        if (dis[cur.x][cur.y] <= cur.w)
            continue;
        dis[cur.x][cur.y] = cur.w;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                int new_cost = cur.w + mat[nx][ny];
                if (new_cost < dis[nx][ny]) {
                    Node next = {nx, ny, new_cost};
                    if (mat[nx][ny] == 0)
                        dq.push_front(next);
                    else
                        dq.push_back(next);
                }
            }
        }
    }

    cout << dis[m][n] << "\n";
    return 0;
}