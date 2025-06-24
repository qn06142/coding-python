#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const int MAXN = 1000005;

const long long MOD = 1e9 + 7;
const long long MOD1 = 1e9 + 9;
const int BASE = 373;
const int BASE1 = 313;

long long hashs[MAXN];
long long hashs1[MAXN];
long long reverse_hashs[MAXN];
long long reverse_hashs1[MAXN];
long long powmod[MAXN];
long long powmod1[MAXN];

string s;
int n;

void calcpow() {
    powmod[0] = powmod1[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powmod[i] = (powmod[i - 1] * BASE) % MOD;
        powmod1[i] = (powmod1[i - 1] * BASE1) % MOD1;
    }
}

void calchash() {
    hashs[0]       = 0;
    hashs1[0]      = 0;
    reverse_hashs[n+1]  = 0;
    reverse_hashs1[n+1] = 0;

    for (int i = 1; i <= n; i++) {
        hashs[i]  = (hashs[i-1]  * BASE  + (int)(unsigned char)s[i-1]) % MOD;
        hashs1[i] = (hashs1[i-1] * BASE1 + (int)(unsigned char)s[i-1]) % MOD1;
    }
    for (int i = n; i >= 1; i--) {
        reverse_hashs[i]  = (reverse_hashs[i+1]  * BASE  + (int)(unsigned char)s[i-1]) % MOD;
        reverse_hashs1[i] = (reverse_hashs1[i+1] * BASE1 + (int)(unsigned char)s[i-1]) % MOD1;
    }

}

pair<int, int> get_prefix_hash(int l, int r) {
    long long hash_value = ((hashs[r] - hashs[l - 1] * powmod[r - l + 1]) % MOD + MOD) % MOD;
    long long hash_value1 = ((hashs1[r] - hashs1[l - 1] * powmod1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    return {hash_value, hash_value1};
}

pair<int, int> get_suffix_hash(int l, int r) {
    long long hash_value = ((reverse_hashs[l] - reverse_hashs[r + 1] * powmod[r - l + 1]) % MOD + MOD) % MOD;
    long long hash_value1 = ((reverse_hashs1[l] - reverse_hashs1[r + 1] * powmod1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    return {hash_value, hash_value1};
}
bool is_pal(int l, int r) {
    if (l > r) return true;
    return get_prefix_hash(l, r) == get_suffix_hash(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    calcpow();
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        n = (int)s.size();

        calchash();

        int l = 1, r = n;
        while (l < r && s[l - 1] == s[r - 1]) {
            l++;
            r--;
        }

        if (l >= r) {
            cout << s << '\n';
            continue;
        }
        int best_pref = 0;
        for (int i = r; i >= l; --i) {
            if (is_pal(l, i)) {
                best_pref = i - l + 1;
                break;
            }
        }
        int best_suf = 0;
        for (int i = l; i <= r; ++i) {
            if (is_pal(i, r)) {
                best_suf = r - i + 1;
                break;
            }
        }

        if (best_pref == 0 && best_suf == 0) {
            best_pref = 1;
        }
        string ans;
        ans.reserve((l - 1) + max(best_pref, best_suf) + (n - r));
        ans += s.substr(0, l - 1);
        if (best_pref >= best_suf) {
            ans += s.substr(l - 1, best_pref);
        } else {
            ans += s.substr(r - best_suf, best_suf);
        }
        ans += s.substr(r);

        cout << ans << '\n';
    }
}