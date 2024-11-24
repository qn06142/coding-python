#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M, N;
    cin >> M >> N;

    vector<vector<char>> grid(M, vector<char>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(M, vector<int>(N, 0));
    int maxSide = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '.') {
                if (i == 0 || j == 0) {

                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    cout << 4 * maxSide << endl;

    return 0;
}