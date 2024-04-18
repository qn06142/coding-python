#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../headers/debug.h"
#else
#define debug(...) 42
#endif

const int mod = (int) 1e9 + 7;

long long POW(long long a, long long b) {
    if(b == 0) return 1;
    long long res = POW(a, b >> 1);
    res = (res * res) % mod;
    if(b & 1) res = (res * a) % mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #define TASK "papers"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    long long n, m; cin >> m >> n;

    long long S = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        S += x;
    }
    S = m - S;

    if(S < 0) cout << 0;
    else {
        long long ans = 1;
        for(int i = S + 1; i <= S + n - 1; i++) {
            ans = (ans * i) % mod;
        }
        long long gt = 1;
        for(int i = 1; i <= n - 1; i++) gt = (gt * i) % mod;
        ans = (ans * POW(gt, mod - 2)) % mod;
        cout << ans;
    }

    return 0;
} 