#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(K));
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        vector<int> prefix_max(K + 1, 0);
        for (int j = 1; j <= K; ++j) {
            prefix_max[j] = max(prefix_max[j-1], dp[i-1][j]);
        }
        for (int j = 1; j <= K; ++j) {
            dp[i][j] = prefix_max[j-1] + A[i-1][j-1];
        }
    }

    int result = *max_element(dp[N].begin(), dp[N].end());
    cout << result << endl;

    return 0;
}