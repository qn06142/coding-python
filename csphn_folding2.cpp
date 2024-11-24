#include <iostream>
#include <vector>
using namespace std;
#define int long long
char invert(char a) {
    return a == 'B' ? 'A' : 'B';
}

char get(int k, int i, int n) {
    if (i == (1LL << (k - 1LL))) {
        return 'A';
    }
    if ((n - k) % 2 == 0) {
        if (i < (1LL << (k - 1LL))) {
            return get(k - 1LL, i, n);
        } else {
            return invert(get(k - 1LL, (1LL << k) - i, n));
        }
    } else {
        if (i < (1LL << (k - 1LL))) {
            return invert(get(k - 1LL, (1LL << (k - 1LL)) - i, n));
        } else {
            return get(k - 1LL, i - (1LL << (k - 1LL)), n);
        }
    }
}

signed main() {
    int n, i, j;
    cin >> n >> i >> j;
    for (int i_ = i; i_ <= j; ++i_) {
        cout << get(n, i_, n);
    }
    cout << endl;
    return 0;
}
