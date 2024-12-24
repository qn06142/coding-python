#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int p[(int)1e7 + 1], t[(int)1e7 + 1], num[(int)1e7 + 1];
int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }
    return ans;
}
int main() {
    int l = 1, r = 1e7;
    cin >> l >> r;
    for (int i = 2; i <= r; ++i) {
        if (p[i]) continue;
        for (int j = i; j <= r; j += i) {
            p[j] = i;
        }
    }
    t[1] = 1;
    num[1] = 1;
    for (int i = 2; i <= r; ++i) {
        int p1 = p[i], cur = i, cnt = 0;
        int a = 1;
        while (cur % p1 == 0) {
            cur /= p1;
            a *= p1;
            ++cnt;
        }
        int b = i / a;
        if (b == 1) {
            t[i] = 1;
            for (int j = 1; j <= cnt; ++j) {
                b *= p1;
                t[i] = 1LL * t[i] * b % MOD;
            }
            num[i] = cnt + 1;
            continue;
        }
        t[i] = 1LL * fpow(t[a], num[b]) * fpow(t[b], num[a]) % MOD;
        num[i] = num[a] * num[b];
    }
    int res = 0;
    for (int i = l; i <= r; ++i) {
        res = (res + t[i]) % MOD;
    }
    cout << res << '\n';
    // cerr << "\nTime: " << setprecision(5) << fixed << (double)clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
