#include <iostream>
using namespace std; 
const __int128 MOD = 1e9 + 7;

__int128 count_divisible(__int128 l, __int128 r, __int128 n) {
    return r / n - (l - 1) / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        __int128 l, r, n;
        long long tmp, tmp1, tmp2;
        cin >> tmp >> tmp1 >> tmp2;
        l = tmp;
        r = tmp1;
        n = tmp2;

        __int128 total_pairs = (r - l + 1) * (r - l + 2) / 2;

        __int128 divisible_count = count_divisible(l, r, n);

        __int128 invalid_pairs = divisible_count * (divisible_count + 1) / 2;

        __int128 valid_pairs = (total_pairs - invalid_pairs + MOD) % MOD;

        cout << (long long) valid_pairs << '\n';
    }

    return 0;
}