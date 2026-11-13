#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int dp[8][8], ndp[8][8], add[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int m = 0; m < 8; m++) {
        int a = (m >> 2) & 1;
        int b = (m >> 1) & 1;
        int c = m & 1;

        if (b == c && a != b) add[m] |= 4;
        if (a == c && b != a) add[m] |= 2;
        if (a == b && c != a) add[m] |= 1;
    }

    dp[7][0] = 1;

    for (char ch : s) {
        int bit = ch - '0';
        memset(ndp, 0, sizeof(ndp));

        for (int tight = 0; tight < 8; tight++) {
            for (int cond = 0; cond < 8; cond++) {
                int val = dp[tight][cond];
                if (!val) continue;

                for (int m = 0; m < 8; m++) {
                    int a = (m >> 2) & 1;
                    int b = (m >> 1) & 1;
                    int c = m & 1;

                    if ((tight & 4) && a > bit) continue;
                    if ((tight & 2) && b > bit) continue;
                    if ((tight & 1) && c > bit) continue;

                    int nt = 0;

                    if ((tight & 4) && a == bit) nt |= 4;
                    if ((tight & 2) && b == bit) nt |= 2;
                    if ((tight & 1) && c == bit) nt |= 1;

                    int nc = cond | add[m];

                    ndp[nt][nc] += val;
                    if (ndp[nt][nc] >= mod)
                        ndp[nt][nc] -= mod;
                }
            }
        }

        memcpy(dp, ndp, sizeof(dp));
    }

    int ans = 0;

    for (int tight = 0; tight < 8; tight++) {
        ans += dp[tight][7];
        if (ans >= mod) ans -= mod;
    }

    cout << ans << '\n';
}