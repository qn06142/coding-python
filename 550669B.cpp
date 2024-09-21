#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long mod = 1e9 + 7;
const long long modsquared = (mod * mod);
const int base = 373;
const int MAXN = 1e6 + 5;

long long hashs[MAXN];
long long powmod[MAXN];
string s;

// Precompute powers of base modulo mod
void calcpow(int max_len) {
    powmod[0] = 1;
    for (int i = 1; i <= max_len; i++) {
        powmod[i] = (base * powmod[i - 1]) % mod;
    }
}

// Precompute hash values of all prefixes of s
void calchash() {
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + (int)s[i - 1]) % mod;
    }
}

// Compute hash of substring s[l...r] (1-based)
long long calchash(int l, int r) {
    return ((long long)hashs[r] - (long long)hashs[l - 1] * powmod[r - l + 1] + modsquared) % mod;
}

// Function to find all possible cycle lengths
vector<int> findCycles() {
    int n = s.size();
    vector<int> cycles;

    calcpow(n);
    calchash();

    for (int L = 1; L <= n; ++L) {
        bool valid = true;
        long long prefix_hash = calchash(1, L);

        // Check each block of length L
        for (int start = L + 1; start <= n; start += L) {
            if (start + L - 1 <= n and calchash(start, start + L - 1) != prefix_hash) {
                valid = false;
                break;
            }
        }

        // Check the last segment
        int remainder_len = n - (n / L) * L;
        if (valid && remainder_len > 0 && calchash(n - remainder_len + 1, n) != calchash(1, remainder_len)) {
            valid = false;
        }

        if (valid) {
            cycles.push_back(L);
        }
    }
    return cycles;
}

int main() {
    cin >> s;
    vector<int> cycles = findCycles();
    for (int cycle : cycles) {
        cout << cycle << " ";
    }
    cout << endl;
    return 0;
}
