#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countMaximalSubsets(int N) {

    vector<int> dp(N + 1, 0);

    dp[0] = 1;  
    dp[1] = 1;  

    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return (dp[N] - dp[N - 1] + MOD) % MOD;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << countMaximalSubsets(N) + 1 << endl;
    }
    return 0;
}