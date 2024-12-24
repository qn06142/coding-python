#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 1000;
int N, M, Q;
int grid[MAX_N + 1][MAX_N + 1];
long long prefix[MAX_N + 1][MAX_N + 1];

// Calculate prefix sums
void computePrefixSums() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefix[i][j] = grid[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

// Calculate sum of treasures in a square
long long getSum(int x1, int y1, int x2, int y2) {
    x1 = max(1, x1);
    y1 = max(1, y1);
    x2 = min(N, x2);
    y2 = min(M, y2);
    if (x1 > x2 || y1 > y2) return 0;
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    computePrefixSums();

    cin >> Q;
    while (Q--) {
        int R, C, K;
        cin >> R >> C >> K;
        
        int sz = 0;
        long long totalDistance = 0;
        int treasuresCollected = 0;

        while (treasuresCollected < K) {
            int outerSum = getSum(R - sz, C - sz, R + sz, C + sz);
            int innerSum = (sz > 0) ? getSum(R - sz + 1, C - sz + 1, R + sz - 1, C + sz - 1) : 0;
            int shellSum = outerSum - innerSum;

            int remaining = K - treasuresCollected;

            if (shellSum >= remaining) {
                totalDistance += 2LL * sz * remaining;
                treasuresCollected += remaining;
            } else {
                totalDistance += 2LL * sz * shellSum;
                treasuresCollected += shellSum;
                sz++;
            }
        }

        cout << totalDistance << '\n';
    }

    return 0;
}
