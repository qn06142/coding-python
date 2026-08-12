#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 505;
const int MOD = 1e9 + 7;

long long dp[MAXN][MAXN];
long long C[MAXN][MAXN];

// Precompute combinations nCr % MOD using Pascal's Triangle
void precompute_combinations() {
    for (int i = 0; i < MAXN; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_combinations();

    string s;
    if (!(cin >> s)) return 0;
    int n = s.size();
    s = " " + s; 
    for (int i = 1; i <= n + 1; i++) {
        dp[i][i - 1] = 1;
    }
    for (int len = 2; len <= n; len += 2) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k <= j; k += 2) {
                if (s[i] == s[k]) {
                    long long ways = (dp[i + 1][k - 1] * dp[k + 1][j]) % MOD;
                    ways = (ways * C[len / 2][(j - k) / 2]) % MOD;

                    dp[i][j] = (dp[i][j] + ways) % MOD;
                }
            }
        }
    }

    cout << dp[1][n];
}