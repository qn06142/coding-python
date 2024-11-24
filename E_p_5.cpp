#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const long long base = 373;

long long hashs[(int)1e6 + 5];
long long powmod[(int)1e6 + 5];
string S;
long long n;

void calcpow() {
    powmod[0] = 1;
    for (long long i = 1; i <= n; i++) {
        powmod[i] = (powmod[i - 1] * base) % mod;
    }
}

void calchash() {
    for (long long i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + S[i - 1]) % mod;
    }
}

long long get_prefix_hash(int l, int r) {
    long long hash_value = (hashs[r] - hashs[l - 1] * powmod[r - l + 1] % mod + mod) % mod;
    return hash_value;
}

long long get_suffix_hash(int l, int r) {
    return get_prefix_hash(n - r + 1, n - l + 1);  // Use the prefix hash for reversed indices.
}

int main() {
    cin >> S;
    n = S.size();

    calcpow();
    calchash();

    vector<int> borders;
    for (int len = 1; len < n; len++) {
        if (get_prefix_hash(1, len) == get_suffix_hash(1, len)) {
            borders.push_back(len);
        }
    }

    for (int len : borders) {
        cout << len << " ";
    }

    return 0;
}
