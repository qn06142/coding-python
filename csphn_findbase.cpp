#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll binpow(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

ll find_smallest_a(ll x) {
    ll smallest_a = x; // Initialize with the maximum possible a (which is x when b = 1)
    
    for (int b = 2; b < 64; ++b) { // Iterate over possible b values
        ll lo = 1, hi = pow(x, 1.0 / b) + 1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll mid_pow = binpow(mid, b);
            if (mid_pow == x) {
                smallest_a = min(smallest_a, mid);
                break;
            } else if (mid_pow < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return smallest_a;
}


int main() {
    int q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        cout << find_smallest_a(x) << endl;
    }
    return 0;
}
