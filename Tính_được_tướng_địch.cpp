#include <bits/stdc++.h>
using namespace std;

const int dig[4] = {3, 5, 7, 9};
const int maxn = 20;

long long memo[maxn][315][16];
char s[25];


long long calc(long long n) {
    if (n <= 0) return 0;

    sprintf(s, "%lld", n);
    int L = strlen(s);

    long long ans = 0;

    for (int len = 1; len < L; len++) {
        for (int i = 0; i < 4; i++) {
            ans += memo[len - 1][dig[i] % 315][1 << i];
        }
    }

    int rem = 0;
    int mask = 0;
    bool ok = true;

    for (int pos = 0; pos < L; pos++) {
        int lim = s[pos] - '0';
        bool matched = false;

        for (int i = 0; i < 4; i++) {
            int d = dig[i];
            if (d < lim) {
                int nr = (rem * 10 + d) % 315;
                ans += memo[L - pos - 1][nr][mask | (1 << i)];
            } else if (d == lim) {
                rem = (rem * 10 + d) % 315;
                mask |= 1 << i;
                matched = true;
                break;
            } else {
                break;
            }
        }

        if (!matched) {
            ok = false;
            break;
        }
    }

    if (ok) {
        bool valid = true;
        for (int i = 0; i < 4; i++) {
            if ((mask >> i) & 1) {
                if (rem % dig[i] == 0) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int rem = 0; rem < 315; rem++) {
        for (int mask = 0; mask < 16; mask++) {
            bool ok = true;
            for (int i = 0; i < 4; i++) {
                if ((mask >> i) & 1) {
                    if (rem % dig[i] == 0) {
                        ok = false;
                        break;
                    }
                }
            }
            memo[0][rem][mask] = ok;
        }
    }

    for (int len = 1; len <= 19; len++) {
        for (int rem = 0; rem < 315; rem++) {
            for (int mask = 0; mask < 16; mask++) {
                long long &cur = memo[len][rem][mask];
                cur = 0;
                for (int i = 0; i < 4; i++) {
                    int nr = (rem * 10 + dig[i]) % 315;
                    cur += memo[len - 1][nr][mask | (1 << i)];
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        long long a, b, k;
        cin >> a >> b >> k;

        long long before = calc(a - 1);
        long long total = calc(b) - before;

        if (total < k) {
            cout << -1 << '\n';
            continue;
        }

        long long target = before + k;
        long long l = a, r = b, ans = -1;

        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (calc(mid) >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }
}