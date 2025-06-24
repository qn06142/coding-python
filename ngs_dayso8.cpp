#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n+1);
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long csum = 0;
    long long ceven = 0;
    for (long long i = 1; i <= k; i++) {
        csum += a[i];
        if (a[i] % 2 == 0) ceven++;
    }

    long long bsum = csum;
    long long beven = ceven;
    long long bstart = 1;

    for (long long start = 2; start <= n - k + 1; start++) {

        csum -= a[start - 1];
        if (a[start - 1] % 2 == 0) ceven--;

        long long in_idx = start + k - 1;
        csum += a[in_idx];
        if (a[in_idx] % 2 == 0) ceven++;

        if (csum > bsum
            || (csum == bsum && ceven > beven)
            || (csum == bsum && ceven == beven && start < bstart)) {
            bsum = csum;
            beven = ceven;
            bstart = start;
        }
    }

    cout << bstart << " " << (bstart + k - 1) << "\n";
}