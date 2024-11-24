#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1500;
int r, c;
char lake[MAX][MAX];
bool visited[MAX][MAX];
int day[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> swans;
queue<pair<int, int>> water, next_water;

bool can_meet(int max_day) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));
    q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == swans[1].first && y == swans[1].second) return true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && day[nx][ny] <= max_day) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

void bfs_for_water() {
    while (!water.empty()) {
        auto [x, y] = water.front(); water.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                day[nx][ny] = day[x][y] + 1;
                next_water.push({nx, ny});
            }
        }
    }
    swap(water, next_water);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    swans.clear();
    while (!water.empty()) water.pop();
    while (!next_water.empty()) next_water.pop();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> lake[i][j];
            day[i][j] = -1;
            if (lake[i][j] != 'X') {
                water.push({i, j});
                day[i][j] = 0;
            }
            if (lake[i][j] == 'L') {
                swans.push_back({i, j});
            }
        }
    }

    while (!water.empty()) {
        bfs_for_water();
    }

    int left = 0, right = r * c, answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_meet(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
