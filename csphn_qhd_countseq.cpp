#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<int> mobius(int n) {
    vector<int> mu(n + 1, 1);
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = mu[i] * mu[p];
            }
        }
    }
    return mu;
}

int main() {
    int t;
    cin >> t;
    vector<int> mu = mobius(1000000);
    while (t--) {
        int s;
        cin >> s;
        vector<int> dp(s + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= s; ++i) {
            for (int j = i; j <= s; ++j) {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }

        int result = 0;
        for (int d = 1; d <= s; ++d) {
            if (s % d == 0) {
                result = (result + mu[d] * dp[s / d]) % MOD;
                if (result < 0) result += MOD;
            }
        }
        cout << result << endl;
    }
    return 0;
}
