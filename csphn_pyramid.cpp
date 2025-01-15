<<<<<<< Updated upstream
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

=======
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#pragma GCC optimize("trapv")
using namespace std;

using ll = __int128;

ll roll(ll i, ll n) {
    return (i + n - 1) % n + 1;
}

int char_map(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A';
    }
    return -1;
}

ll get_offset(ll row) {
    return (row * (row - 1)) / 2 + 1ll;
}

ll get_position(ll i, ll j) {
    ll offset = get_offset(i);
    return (i % 2 == 1) ? offset + (j - 1) : offset + (i - j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int q;
    cin >> n;
    string s;
    cin >> s;
    for (auto &c : s) c = toupper(c);

    int length = s.size();
    cin >> q;

    vector<vector<int>> prefix_mod(26, vector<int>(length + 1, 0));

    for (int i = 0; i < length; ++i) {
        int mapped_index = char_map(s[i]);
        if (mapped_index != -1) {
            prefix_mod[mapped_index][i + 1]++;
        }
    }

    for (int c = 0; c < 26; ++c) {
        for (int i = 1; i <= length; ++i) {
            prefix_mod[c][i] += prefix_mod[c][i - 1];
        }
    }

    vector<string> results;

>>>>>>> Stashed changes
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
<<<<<<< Updated upstream
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
=======
            long long i;
            char target;
            cin >> i >> target;

            int mapped_index = char_map(target);
            if (mapped_index == -1) {
                results.emplace_back("0");
                continue;
            }

            ll offset = get_offset(i);
            ll start_mod = roll(get_position(i, 1), length);
            ll end_mod = roll(get_position(i, i), length);

            if (i % 2 == 0) {
                swap(start_mod, end_mod);
            }

            ll full_repeats = (i - 1) / length;
            ll count = full_repeats * prefix_mod[mapped_index][length];

            if (start_mod <= end_mod) {
                count += prefix_mod[mapped_index][end_mod] - prefix_mod[mapped_index][start_mod - 1];
            } else {
                count += prefix_mod[mapped_index][length] - prefix_mod[mapped_index][start_mod - 1];
                count += prefix_mod[mapped_index][end_mod];
            }

            results.emplace_back(to_string(static_cast<long long>(count)));

        } else if (t == 2) {
            int i, j;
            cin >> i >> j;

            ll pos = get_position(i, j);
            char result = s[(pos - 1) % length];
            results.emplace_back(string(1, result));
        }
    }

    for (const auto &res : results) {
        cout << res << '\n';
    }

    return 0;
}
>>>>>>> Stashed changes
