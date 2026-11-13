#include <bits/stdc++.h>
using namespace std;

const int maxv = 10000000;

int spf[maxv + 1];
int a[maxv + 1], b[maxv + 1];

void sieve() {
    for (int i = 2; i <= maxv; i++) {
        if (!spf[i]) {
            spf[i] = i;

            if (1LL * i * i <= maxv) {
                for (long long j = 1LL * i * i; j <= maxv; j += i) {
                    if (!spf[j])
                        spf[j] = i;
                }
            }
        }
    }
}

void factor(int x, int cnt[]) {
    while (x > 1) {
        int p = spf[x];

        while (x % p == 0) {
            cnt[p]++;
            x /= p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        factor(x, a);
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        factor(x, b);
    }

    long long ans = 0;

    for (int p = 2; p <= maxv; p++) {
        int c = min(a[p], b[p]);
        int x = (a[p] - c) / 2;
        int y = (b[p] - c) / 2;

        ans += 2LL * c + x + 3LL * y;
    }

    cout << ans << '\n';

    for (int p = 2; p <= maxv; p++) {
        int c = min(a[p], b[p]);

        for (int i = 0; i < c; i++) {
            cout << p << " W\n";
            cout << p << " L\n";
        }

        int x = (a[p] - c) / 2;

        for (int i = 0; i < x; i++)
            cout << p << " L\n";

        int y = (b[p] - c) / 2;

        for (int i = 0; i < y; i++) {
            cout << p << " W\n";
            cout << p << " W\n";
            cout << p << " L\n";
        }
    }
}