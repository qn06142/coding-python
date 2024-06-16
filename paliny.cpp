#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const long long base = 373;
vector<long long> hashs, powmod;

void calcpow(int n) {
    powmod.resize(n + 1);
    powmod[0] = 1;
    for(int i = 1; i <= n; i++) {
        powmod[i] = (base * powmod[i - 1]) % mod;
    }
}

void calchash(const string &S, int n) {
    hashs.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        hashs[i] = (hashs[i - 1] * base + S[i - 1]) % mod;
    }
}

long long gethash(int l, int r) {
    long long hash_value = (hashs[r + 1] - (hashs[l] * powmod[r - l + 1]) % mod + mod) % mod;
    return hash_value;
}

bool is_palindrome(const string &S, int len) {
    for(int i = 0; i <= S.size() - len; i++) {
        int j = i + len - 1;
        int mid = (i + j) / 2;
        if(gethash(i, mid) == gethash(j - mid + i, j)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    string S;
    cin >> n >> S;

    calcpow(n);
    calchash(S, n);

    int l = 1, r = n, result = 1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(is_palindrome(S, mid)) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}