#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    __int128 total_sum = (__int128)n * (n + 1) / 2;

    long long full_blocks = n / k;
    long long rem = n % k;

    long long t_full = (full_blocks + 1) / 2;

    __int128 term1 = (__int128)2 * k * t_full * (t_full - 1);
    __int128 term2 = (__int128)t_full * (k + 1);
    __int128 a = (__int128)k * (term1 + term2) / 2;

    if (rem > 0 && (full_blocks % 2) == 0) {
        long long start = full_blocks * k + 1;
        long long end   = n;
        a += (__int128)rem * (start + end) / 2;
    }

    long long answer = (long long)(total_sum - 2 * a);
    cout << answer << "\n";
}