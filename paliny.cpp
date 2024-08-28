#include <iostream>
#include <string>
using namespace std;

long long hashs[(int)1e6 + 5];
long long powmod[(int)1e6 + 5];
const long long mod = 1e9 + 7;
const long long base = 373;

void calcpow() {
    powmod[0] = 1;
    for (long long i = 1; i <= 1e6; i++) {
        powmod[i] = (powmod[i - 1] * base) % mod;
    }
}

string S;
long long n;

void calchash() {
    for (long long i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + S[i - 1]) % mod;
    }
}

long long calchash(long long l, long long r) {
    long long hash_value = (hashs[r] - hashs[l - 1] * powmod[r - l + 1] % mod + mod) % mod;
    return hash_value;
}

bool is_palindrome(int len) {
    for (int i = 0; i <= n - len; i++) {
        int l = i + 1;
        int r = i + len;
        int rev_l = n - r + 1;
        int rev_r = n - l + 1;
        if (calchash(l, r) == calchash(rev_l, rev_r)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> S;
    calcpow();
    calchash();

    int low = 1, high = n, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_palindrome(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
