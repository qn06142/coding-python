#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const long long MOD = 1e9 + 7;
const long long MODSQUARED = MOD * MOD;
const int BASE = 373;
long long hashs[MAXN], powmod[MAXN];
string s;
int n;

void calcpow() {
    powmod[0] = 1;
    for (int i = 1; i <= n; i++) {
        powmod[i] = (powmod[i - 1] * BASE) % MOD;
    }
}

void calchash() {
    for (int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
    }
}

long long gethash(int l, int r) {
    long long res = (hashs[r] - hashs[l - 1] * powmod[r - l + 1] % MOD + MODSQUARED) % MOD;
    return res;
}

int LCP(int i, int j) {
    int lo = 0, hi = n - max(i, j) + 1, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (gethash(i, i + mid - 1) == gethash(j, j + mid - 1))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {

    cin >> s;
    n = s.size();
    s = ' ' + s; 

    int q;
    cin >> q;

    calcpow();
    calchash();

    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << LCP(i, j) << '\n';
    }

    return 0;
}