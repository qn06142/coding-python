#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<long long, int> prefmap;
    prefmap[0] = 0;
    long long pref = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'O') pref += 1;
        else pref -= k;

        if (prefmap.count(pref)) {
            ans = max(ans, i + 1 - prefmap[pref]);
        } else {
            prefmap[pref] = i + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
