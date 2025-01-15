#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const ll BASE1 = 31, BASE2 = 59;

vector<ll> power1, power2, hash1, hash2;

void precompute_powers(int n) {
    power1.resize(n + 1, 1);
    power2.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        power1[i] = power1[i - 1] * BASE1 % MOD1;
        power2[i] = power2[i - 1] * BASE2 % MOD2;
    }
}

void compute_hashes(const string &s) {
    int n = s.size();
    hash1.resize(n + 1, 0);
    hash2.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        hash1[i] = (hash1[i - 1] * BASE1 + (s[i - 1] - 'a' + 1)) % MOD1;
        hash2[i] = (hash2[i - 1] * BASE2 + (s[i - 1] - 'a' + 1)) % MOD2;
    }
}

pair<ll, ll> get_hash(int l, int r) {
    ll h1 = (hash1[r] - hash1[l - 1] * power1[r - l + 1] % MOD1 + MOD1) % MOD1;
    ll h2 = (hash2[r] - hash2[l - 1] * power2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {h1, h2};
}

int compare_substrings(int l1, int r1, int l2, int r2, const string &s) {
    int len1 = r1 - l1 + 1;
    int len2 = r2 - l2 + 1;
    int min_len = min(len1, len2);

    int low = 0, high = min_len;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (get_hash(l1, l1 + mid - 1) == get_hash(l2, l2 + mid - 1)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    int diff_pos = low;
    if (diff_pos < min_len) {
        if (s[l1 + diff_pos - 1] < s[l2 + diff_pos - 1]) return 0;
        if (s[l1 + diff_pos - 1] > s[l2 + diff_pos - 1]) return 1;
    }

    if (len1 == len2) return 2;
    return len1 < len2 ? 0 : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    precompute_powers(n);
    compute_hashes(s);

    int q;
    cin >> q;
    while (q--) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        cout << compare_substrings(l, r, u, v, s) << '\n';
    }

    return 0;
}