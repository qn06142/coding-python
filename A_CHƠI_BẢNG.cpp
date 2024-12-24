#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const long long INF = LLONG_MIN;

int n;
int grid[3][MAXN];
vector<int> numList[3];
int cnt[3];
long long dp[2][MAXN][MAXN][MAXN];

inline void maximize(long long &x, long long y) {
    if (x < y) x = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                numList[i].push_back(grid[i][j]);
            } else {
                cnt[i]++;
            }
        }
    }

    memset(dp, 0xcf, sizeof(dp)); 
    dp[0][0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int cur = i & 1;
        int prev = 1 - cur;
        for (int x = 0; x <= min(cnt[0], i); x++) {
            for (int y = 0; y <= min(cnt[1], i); y++) {
                for (int z = 0; z <= min(cnt[2], i); z++) {
                    dp[cur][x][y][z] = -INF;

                    if (x < i && y < i && z < i) {
                        maximize(dp[cur][x][y][z], dp[prev][x][y][z] + numList[0][i - x - 1] * numList[1][i - y - 1] * numList[2][i - z - 1]);
                    }

                    if (x > 0 && y < i && z < i) {
                        maximize(dp[cur][x][y][z], dp[prev][x - 1][y][z]);
                    }

                    if (x < i && y > 0 && z < i) {
                        maximize(dp[cur][x][y][z], dp[prev][x][y - 1][z]);
                    }

                    if (x < i && y < i && z > 0) {
                        maximize(dp[cur][x][y][z], dp[prev][x][y][z - 1]);
                    }

                    if (x > 0 && y > 0 && z < i) {
                        maximize(dp[cur][x][y][z], dp[prev][x - 1][y - 1][z]);
                    }

                    if (x > 0 && y < i && z > 0) {
                        maximize(dp[cur][x][y][z], dp[prev][x - 1][y][z - 1]);
                    }

                    if (x < i && y > 0 && z > 0) {
                        maximize(dp[cur][x][y][z], dp[prev][x][y - 1][z - 1]);
                    }

                    if (x > 0 && y > 0 && z > 0) {
                        maximize(dp[cur][x][y][z], dp[prev][x - 1][y - 1][z - 1]);
                    }
                }
            }
        }
    }

    cout << dp[n & 1][cnt[0]][cnt[1]][cnt[2]] << "\n";
    return 0;
}