#include <iostream>
#include <vector>
using namespace std;

const int MOD = 123456789;

int countStrictlyIncreasingPartitions(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // base case: one way to partition 0

    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= j; i--) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << countStrictlyIncreasingPartitions(n) << endl;
    return 0;
}
