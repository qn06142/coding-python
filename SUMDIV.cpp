#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long sum_of_first_n(long long n) {
    return n * (n + 1) / 2;
}

long long solve(long long L, long long R) {
    long long s = 0;
    long long hi = 1e16; 
    long long lim = min(R - L + 1, (long long)sqrtl(R) + 1);

    if (L <= R - L + 1) {
        return sum_of_first_n(R) - sum_of_first_n(L - 1);
    }

    for (long long i = 1; i <= sqrtl(R); ++i) {
        long long st = max(lim, (L + i - 1) / i); 
        long long ed = min(R / i, hi);           

        if ((L +i - 1) / i <= R / i) {
            s += i;
        }

        if (ed >= st) {
            s += sum_of_first_n(ed) - sum_of_first_n(st - 1);
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
    long long L, R;
    cin >> L >> R;
    cout << solve(L, R) << endl;
    return 0;
}