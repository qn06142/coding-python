#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 500;
const int MAX_R = 1000;

int n, m, q, k;
long long total_damage = 0;
vector<vector<int>> a;
vector<pair<int, int>> special_points;

void process_storm(int w, int R1, int R2, int x, int y) {
    vector<vector<bool>> affected(n, vector<bool>(m, false));
    for (int i = max(0, x - R1); i <= min(n - 1, x + R1); i++) {
        for (int j = max(0, y - R1); j <= min(m - 1, y + R1); j++) {
            int dist = abs(i - x) + abs(j - y);
            if (dist >= R2 && dist <= R1 && !affected[i][j]) {
                int damage = min(w, a[i][j]);
                total_damage += damage;
                a[i][j] -= damage;
                affected[i][j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q >> k;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    special_points.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> special_points[i].first >> special_points[i].second;
        special_points[i].first--; 
        special_points[i].second--;
    }

    for (int i = 0; i < k; i++) {
        int w, R1, R2, x, y;
        cin >> w >> R1 >> R2 >> x >> y;
        x--; y--; 
        process_storm(w, R1, R2, x, y);
    }

    cout << total_damage << "\n";
    return 0;
}