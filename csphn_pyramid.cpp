#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_offset(ll row) {
    return (row * (row - 1)) / 2 + 1;
}

int main() {

    ll n;
    cin >> n;

    string s;
    cin >> s;
    ll len = s.size();

    ll q;
    cin >> q;

    vector<vector<ll>> prefix_sums(255, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; ++i) {
        ll offset = get_offset(i);
        for (ll j = 0; j < i; ++j) {
            ll pos;
            if (i % 2 == 1) {

                pos = offset + j;
            } else {

                pos = offset + (i - j - 1);
            }
            char current_char = s[(pos - 1) % len];
            prefix_sums[current_char][i]++;
        }
        for (int c = 0; c < 255; ++c) {
            prefix_sums[c][i] += prefix_sums[c][i - 1];
        }
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            ll i;
            cin >> i;

            char target;
            cin >> target;

            cout << prefix_sums[target][i] - prefix_sums[target][i - 1] << '\n';
        } else if (t == 2) {
            ll i, j;
            cin >> i >> j;

            ll offset = get_offset(i);

            ll pos;
            if (i % 2 == 1) {

                pos = offset + (j - 1);
            } else {

                pos = offset + (i - j);
            }

            char result = s[(pos - 1) % len];
            cout << result << '\n';
        }
    }

    return 0;
}