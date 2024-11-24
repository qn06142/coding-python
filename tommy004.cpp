#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 100;
#define int long long

int prime[MAX];
long c[MAX], f[MAX];
long long pref[MAX];
long t, n, m;

void sieve() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            for (int j = i; j <= MAX; j += i) {
                prime[j] = i;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        c[t]++;
    }

    sieve();

    for (int i = 2; i <= MAX; i++) {
        if (prime[i] == i) { // i is a prime number
            for (int j = i; j <= MAX; j += i) {
                f[i] += c[j];
            }
        }
    }

    for (int i = 2; i <= MAX; i++) {
        pref[i] = pref[i - 1] + f[i];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        r = min((int)1e7, r);
        l = min((int)1e7, l);
        cout << pref[r] - pref[l - 1] << '\n';
    }
}
