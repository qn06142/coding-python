#include <iostream>
#include <string>
using namespace std;

const long long mod = 1e9 + 7;
const long long base = 373;

long long hashs[(int)1e6 + 5];
long long revhash[(int)1e6 + 5];
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
    for (long long i = n; i >= 1; i--) {
        revhash[i] = (revhash[i + 1] * base + S[i - 1]) % mod;
    }
}

long long get_prefix_hash(int l, int r) {
    long long hash_value = (hashs[r] - hashs[l - 1] * powmod[r - l + 1] % mod + mod) % mod;
    return hash_value;
}

long long get_suffix_hash(int l, int r) {
    long long hash_value = (revhash[l] - revhash[r + 1] * powmod[r - l + 1] % mod + mod) % mod;
    return hash_value;
}

bool is_palindrome(int center, int len, bool odd) {
    int l = center - len + 1;
    int r = center + len - (odd ? 1 : 0);

    if (l >= 1 && r <= n && get_prefix_hash(l, r) == get_suffix_hash(l, r)) {
        return true;
    }
    return false;
}

int max_palindrome_length() {
    int max_len = 1;

    for (int center = 1; center <= n; center++) {
        int low = 1, high = min((long long) center, n - center + 1);
        while (low <= high) {
            int len = (low + high) / 2;
            if (is_palindrome(center, len, true)) {
                max_len = max(max_len, (int) 2 * len - 1);
                low = len + 1;
            } else {
                high = len - 1;
            }
        }
    }

    for (int center = 1; center < n; center++) {
        int low = 1, high = min(center,(int) n - center);
        while (low <= high) {
            int len = (low + high) / 2;
            if (is_palindrome(center, len, false)) {
                max_len = max(max_len, (int) 2 * len);
                low = len + 1;
            } else {
                high = len - 1;
            }
        }
    }

    return max_len;
}

int main() {
    cin >> S;
    n = S.size();
    calcpow();
    calchash();

    cout << max_palindrome_length() << endl;
    return 0;
}