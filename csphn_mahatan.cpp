#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
long long grid[MAXN][MAXN];
long long rotated1[MAXN][MAXN];
long long rotated2[MAXN][MAXN];

int n, k;

void rotateGrid() {
    memset(rotated1, 0, sizeof(rotated1));
    memset(rotated2, 0, sizeof(rotated2));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            rotated1[i + j][j - i + n] += grid[i][j];
            rotated2[i + j][i - j + n] += grid[i][j];
        }
    }

    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            rotated1[i][j] += rotated1[i - 1][j] + rotated1[i][j - 1] - rotated1[i - 1][j - 1];
            rotated2[i][j] += rotated2[i - 1][j] + rotated2[i][j - 1] - rotated2[i - 1][j - 1];
        }
    }
}

long long queryRotated(long long rotated[MAXN][MAXN], int i, int j, int d) {
    int r1 = max(1, i - d), c1 = max(1, j - d);
    int r2 = min(2 * n, i + d), c2 = min(2 * n, j + d);

    return rotated[r2][c2] - rotated[r1 - 1][c2] - rotated[r2][c1 - 1] + rotated[r1 - 1][c1 - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }

    rotateGrid();

    long long maxSum = LLONG_MIN;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long sum = queryRotated(rotated1, i + j, j - i + n, k) +
                            queryRotated(rotated2, i + j, i - j + n, k);
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum / 2 << "\n";
    return 0;
}