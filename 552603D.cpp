#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAX_M = 7;
const int MAX_N = 1000;

int m, n;
int a[MAX_M + 1][MAX_N + 1];
int dist[MAX_M + 1][MAX_N + 1][MAX_M + 1][MAX_N + 1];

struct Node {
    int x, y, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void dijkstra(int startX, int startY) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({startX, startY, 0});
    dist[startX][startY][startX][startY] = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int x = node.x;
        int y = node.y;
        int currentCost = node.cost;

        if (currentCost > dist[startX][startY][x][y]) continue;

        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 1 && newX <= m && newY >= 1 && newY <= n) {
                int newCost = currentCost + a[newX][newY];
                if (newCost < dist[startX][startY][newX][newY]) {
                    dist[startX][startY][newX][newY] = newCost;
                    pq.push({newX, newY, newCost});
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int x = 1; x <= m; ++x) {
                for (int y = 1; y <= n; ++y) {
                    dist[i][j][x][y] = INF;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dijkstra(i, j);
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (dist[x][y][u][v] == INF) {
            cout << -1 << endl; 
        } else {
            cout << dist[x][y][u][v] + a[x][y] << endl;
        }
    }

    return 0;
}