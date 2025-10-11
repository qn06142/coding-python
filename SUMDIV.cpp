#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long sumn(long long n) {
    return n * (n + 1) / 2;
}

long long solve(long long l, long long r) {
    long long s = 0;
    long long hi = 1e16; 
    long long lim = min(r - l + 1, (long long)sqrtl(r) + 1);

    if (l <= r - l + 1) {
        return sumn(r) - sumn(l - 1);
    }

    for (long long i = 1; i <= sqrtl(r); ++i) {
        long long st = max(lim, (l + i - 1) / i); 
        long long ed = min(r / i, hi);           

        if ((l +i - 1) / i <= r / i) {
            s += i;
        }

        if (ed >= st) {
            s += sumn(ed) - sumn(st - 1);
            if (ed == i) {
                s -= i; 
            }
            hi = min(hi, st - 1);
        }
    }
    return s;
}

int main() {
    #ifdef ONLINE_JUDGE
    freopen("sumdiv.inp", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
    #endif
    long long l, r;
    cin >> l >> r;
    cout << solve(l, r);
}