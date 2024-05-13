#include<iostream>

using namespace std;

const int maxn = 1e3 + 5;

long long dp[maxn][maxn];
long long pref[maxn];
int mod = 1e9 + 7;
int main() {
    long long n, m;

    dp[1][1] = 1;

    for(int i = 1; i <= 2 * m; i++) {
        for(int j = 1; j <= n; j++) {
            pref[j] = (pref[j - 1] + dp[i - 1][j]) % mod;
        }
        for(int j = 1; j <= n; j++) {
            dp[i][j] = pref[j];
        }
    }
    cout << dp[2 * m][n];
}