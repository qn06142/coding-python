#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e4 + 5; // Maximum length of the string
const ll base = 27; // Base for the polynomial hash
const ll mod = 1e9 + 9; // Modulo value for the hash

int n, ans;
ll p[N];
string s, t;
vector<ll> S, T;

// Function to compute hash values for the string s
vector<ll> getHash(const string &s) {
    vector<ll> h(s.size(), 0);
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++) {
        h[i] = (h[i - 1] * base + s[i] - 'a' + 1) % mod;
    }
    return h;
}

// Function to get the hash of the substring s[l:r]
ll getSubstringHash(const vector<ll> &h, int l, int r) {
    if (l == 0) return h[r];
    ll ans = (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

// Function to check if there exists a palindrome of length len
bool check(int len) {
    for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (getSubstringHash(S, i, j) == getSubstringHash(T, n - j - 1, n - i - 1)) {
            return true;
        }
    }
    return false;
}

// Binary search to find the longest palindromic substring
void solve(int L, int R, int k) {
    while (L <= R) {
        int mid = (L + R) / 2;
        int len = 2 * mid + k;
        if (check(len)) {
            ans = max(ans, len);
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin.ignore();
    getline(cin, s);

    // Prepare the reversed string t
    t = s;
    reverse(t.begin(), t.end());

    // Compute the hashes for the string s and its reverse t
    S = getHash(s);
    T = getHash(t);

    // Precompute powers of base % mod
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * base % mod;
    }

    // Solve for odd and even length palindromes
    solve(0, (n - 1) / 2, 1);
    solve(1, n / 2, 0);

    // Output the length of the longest palindromic substring
    cout << ans << '\n';

    return 0;
}