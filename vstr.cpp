#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;

    s = ' ' + s;  // Make string 1-indexed
    ll a = 0, b = 0, l = 1, r = 1, temp = 0, ans = 0;
    s += ' ';  // Add a space to handle edge case

    if (s[l] == 'a') ++a;
    if (s[l] == 'b') ++b;

    while (l <= n) {
        if (r < l) {
            temp = 0;
            a = b = 0;
            if (s[l] == 'a') ++a;
            if (s[l] == 'b') ++b;
        } else {
            if (s[l - 1] == 'a') {
                temp -= b;
                --a;
            }
            if (s[l - 1] == 'b') {
                --b;
            }
        }

        while (r <= n && temp <= k) {
            ++r;
            if (s[r] == 'b') {
                temp += a;
                ++b;
            }
            if (s[r] == 'a') {
                ++a;
            }
        }

        ans = max(ans, r - l);
        ++l;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}