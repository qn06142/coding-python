#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> X[i];
    }

    map<int, int> bonus;
    for (int i = 0; i < M; ++i) {
        int C, Y;
        cin >> C >> Y;
        bonus[C] = Y;
    }

    vector<long long> dp(N + 1, 0);
    long long max_yen = 0;

    for (int i = 1; i <= N; ++i) {
        vector<long long> new_dp(N + 1, 0);

        new_dp[0] = max_yen;

        for (int j = 1; j <= i; ++j) {
            new_dp[j] = dp[j - 1] + X[i];
            if (bonus.count(j)) {
                new_dp[j] += bonus[j];
            }
            max_yen = max(max_yen, new_dp[j]);
        }

        dp = new_dp;
    }

    cout << max_yen << endl;
    return 0;
}