#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e6 + 7;
const ll mod = 1e9 + 427;
const int base = 311;

ll h[N], p[N];
string s;
int n;

void build_hash() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * base % mod;
        h[i] = (h[i - 1] * base + s[i] - 'A' + 1) % mod;
    }
}

int get_hash(int l, int r) {
    return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("code.inp", "r", stdin);
    freopen("code.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.size();
    s = " " + s; // Adding a space to make the string 1-indexed
    build_hash();

    for (int i = 1; i <= n; i++) {
        ll hi = h[i];
        bool check = true;
        int j = i + 1;
        while (j <= n) {
            if (j + i - 1 <= n) {
                if (hi != get_hash(j, j + i - 1)) {
                    check = false;
                    break;
                }
                j += i;
            } else {
                if (get_hash(j, n) != h[n - j + 1]) {
                    check = false;
                    break;
                }
                j += i;
            }
        }
        if (check) {
            cout << s.substr(1, i);
            return 0;
        }
    }
    return 0;
}
