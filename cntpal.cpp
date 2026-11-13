#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, q;
int odd[maxn], even[maxn], pref[maxn][26];
long long so[maxn], se[maxn];
string s;

void manacher() {
    for (int i = 1, l = 1, r = 0; i <= n; i++) {
        int k = (i > r ? 1 : min(odd[l + r - i], r - i + 1));

        while (i - k >= 1 && i + k <= n && s[i - k] == s[i + k]) {
            k++;
        }

        odd[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    for (int i = 1, l = 1, r = 0; i <= n; i++) {
        int k = (i > r ? 0 : min(even[l + r - i + 1], r - i + 1));

        while (i - k - 1 >= 1 && i + k <= n && s[i - k - 1] == s[i + k]) {
            k++;
        }

        even[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s;
    s = " " + s;

    manacher();

    int mo = 0, me = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i][j] = pref[i - 1][j] + (s[i] - 'a' == j);
        }

        so[i] = so[i - 1] + odd[i];
        se[i] = se[i - 1] + even[i];

        mo = max(mo, odd[i]);
        me = max(me, even[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        long long len = r - l + 1;

        if (pref[r][s[l] - 'a'] - pref[l - 1][s[l] - 'a'] == len) {
            cout << len * (len + 1) / 2 << '\n';
            continue;
        }

        long long ans = so[r] - so[l - 1] + se[r] - se[l - 1];

        int mid = (l + r) / 2;

        for (int i = l; i <= min(mid, l + mo); i++) {
            ans -= max(0, odd[i] - (i - l + 1));
        }

        for (int i = max(mid + 1, r - mo); i <= r; i++) {
            ans -= max(0, odd[i] - (r - i + 1));
        }

        mid = (l + r + 1) / 2;

        for (int i = l; i <= min(mid, l + me); i++) {
            ans -= max(0, even[i] - (i - l));
        }

        for (int i = max(mid + 1, r - me); i <= r; i++) {
            ans -= max(0, even[i] - (r - i + 1));
        }

        cout << ans << '\n';
    }
}