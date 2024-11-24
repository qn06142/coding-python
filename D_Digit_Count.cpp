#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(const vector<int>& S, int n) {
    int m = S.size();

    vector<vector<int>> dp(n + 1, vector<int>(10, 0));

    for (int digit : S) {
        dp[1][digit] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int x : S) {
            if (dp[i][x] > 0) { 
                for (int y : S) {
                    if (abs(x - y) <= 2) { 
                        dp[i + 1][y] += dp[i][x];
                    }
                }
            }
        }
    }

    int result = 0;
    for (int x : S) {
        result += dp[n][x];
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int m, n;
        cin >> m >> n;
        vector<int> S(m);
        for (int i = 0; i < m; ++i) {
            cin >> S[i];
        }

        int result = solve(S, n);
        cout << "Case " << t << ": " << result << endl;
    }

    return 0;
}