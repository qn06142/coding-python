#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 7;
const ll mod = 1e9 + 427;
const int base = 317;

ll h[2][N], p[N];
string s, t;
int n;

void build_hash() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * base % mod;
        h[0][i] = (h[0][i - 1] * base + s[i] - 'a' + 1) % mod;
        h[1][i] = (h[1][i - 1] * base + t[i] - 'a' + 1) % mod;
    }
}

int get_reverse_hash(int l, int r) {
    l = n - l + 1;
    r = n - r + 1;
    swap(l, r);
    return (h[1][r] - h[1][l - 1] * p[r - l + 1] + mod * mod) % mod;
}

int get_hash(int l, int r) {
    return (h[0][r] - h[0][l - 1] * p[r - l + 1] + mod * mod) % mod;
}

bool check_palindrome(int l, int r) {
    int mid = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        return get_hash(l, mid) == get_reverse_hash(mid + 1, r);
    }
    return get_hash(l, mid) == get_reverse_hash(mid, r);
}

void solve() {
    cin >> s;
    n = s.size();
    t = s;
    reverse(t.begin(), t.end());
    s = " " + s; 
    t = " " + t;
    build_hash();

    for (int i = 1; i <= n; i++) {
        if (check_palindrome(i, n)) {
            cout << s.substr(1, n);
            for (int j = i - 1; j >= 1; j--) cout << s[j];
            cout << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q;
    cin >> Q;
    while (Q--) solve();
    return 0;
}