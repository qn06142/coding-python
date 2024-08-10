#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 998244353;
const int MAX_K = 5000;

int main() {
    int Q, K;
    cin >> Q >> K;

    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    
    map<int, int> ball_count;
    
    while (Q--) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            ball_count[x]++;
            for (int j = K; j >= x; --j) {
                dp[j] = (dp[j] + dp[j - x]) % MOD;
            }
        } else if (op == '-') {
            for (int j = x; j <= K; ++j) {
                dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
            }
            ball_count[x]--;
            if (ball_count[x] == 0) {
                ball_count.erase(x);
            }
        }
        
        cout << dp[K] << '\n';
    }

    return 0;
}
