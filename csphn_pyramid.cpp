#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_offset(ll row) {
    return (row * (row - 1)) / 2 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    string s;
    cin >> s;
    ll len = s.size();

    ll q;
    cin >> q;

    while (q--) {
        ll i;
        char t;
        cin >> i >> t;

        ll offset = get_offset(i);
        ll count = 0;

        for (ll j = 0; j < i; ++j) {
            ll pos;
            if (i % 2 == 1) {
                pos = offset + j;
            } else {
                pos = offset + (i - j - 1);
            }

            char c = s[(pos - 1) % len];
            if (c == t) count++;
        }

        cout << count << '\n';
    }

    return 0;
}
