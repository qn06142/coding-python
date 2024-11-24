#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;
const long long modsquared = mod * mod;
const int base = 373;
#define int long long

long long hashs[(int)1e6 + 5];
long long powmod[(int)1e6 + 5];
string s;
int n, k;

void calcpow() {
    powmod[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        powmod[i] = (base * powmod[i - 1]) % mod;
    }
}

void calchash() {
    for (int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + (int)s[i-1]) % mod;
    }
}

int calchash(int l, int r) {
    return ((long long) hashs[r] - (long long) hashs[l - 1] * powmod[r - l + 1] + modsquared) % mod;
}

bool check(int len) {
    unordered_map<int, int> hash_count;
    for (int i = 1; i + len - 1 <= n; i++) {
        int hash_val = calchash(i, i + len - 1);
        hash_count[hash_val]++;
        if (hash_count[hash_val] >= k) return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;

    calcpow();
    calchash();

    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
