#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> jumps(m);
    for (int i = 0; i < m; i++) {
        cin >> jumps[i];
    }

    vector<long long> dp(n + 1, 0);
    dp[1] = 1; 

    for (int i = 1; i <= n; i++) {
        if (dp[i] > 0) {
            for (int j = 0; j < m; j++) {
                int next = i + jumps[j];
                if (next <= n) {
                    dp[next] = (dp[next] + dp[i]) % MOD;
                }
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}