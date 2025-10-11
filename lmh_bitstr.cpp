#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

long long min_flips(const string &s, int m, char target) {
    int n = s.size();
    vector<int> effect(n, 0);
    int curr_flip = 0;
    long long flips = 0;

    for (int i = 0; i < n; i++) {

        if (i >= m) {
            curr_flip -= effect[i - m];
        }

        char val = ((s[i] - '0') ^ (curr_flip & 1)) + '0';
        if (val != target) {

            if (i + m > n) return INF;
            flips++;
            curr_flip++;
            effect[i] = 1;
        }
    }
    return flips;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int m;
    if (!(cin >> s >> m)) return 0;
    int n = s.size();

    if (m > n) {
        bool all_zero = true, all_one = true;
        for (char c : s) {
            if (c != '0') all_zero = false;
            if (c != '1') all_one = false;
        }
        if (all_zero || all_one) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return 0;
    }

    long long to_zero = min_flips(s, m, '0');
    long long to_one  = min_flips(s, m, '1');
    long long ans = min(to_zero, to_one);
    if (ans >= INF) ans = -1;
    cout << ans << "\n";
}
