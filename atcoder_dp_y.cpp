#include <iostream>
#define MOD 1000000007

using namespace std;

int uniquePathsWithObstacles(int A[100][100], int r, int c) {
    int dp[r];
    dp[0] = 1 - A[0][0];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (A[i][j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
    }
    return dp[c-1];
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int A[h][w];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[x-1][y-1] = 1;
    }
    cout << uniquePathsWithObstacles(A, h, w) % MOD << endl;
    return 0;
}

