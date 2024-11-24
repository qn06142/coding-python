#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(X + 1, INF)));
    dp[0][0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= X; ++k) {

                dp[i][j][k] = dp[i - 1][j][k];

                if (j > 0 && k >= A[i]) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - A[i]] + B[i]);
                }
            }
        }
    }

    int G = 0;
    for (int j = 1; j <= N; ++j) {
        for (int k = 0; k <= X; ++k) {
            if (dp[N][j][k] <= Y) {
                G = j;
            }
        }
    }

    cout << G + 1 << "\n"; 
    return 0;
}