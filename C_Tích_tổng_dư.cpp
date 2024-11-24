#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 1;
long long a[maxn], cnt[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, q;
    cin >> n >> q;

    for (long long i = 1; i <= q; i++) {
        long long k, x;
        cin >> k >> x;
        cnt[k] += x;
    }

    for (long long k = 2; k <= n; k++) {
        long long s = 0;
        a[1] += cnt[k];
        while (s * k <= n) {
            s++;
            a[1 + s * k] += k * cnt[k];
            a[s * k] -= k * cnt[k];
        }
    }

    for (long long j = 1; j <= n; j++) {
        a[j] = a[j - 1] + a[j];
    }

    for (long long j = 1; j <= n; j++) {
        a[j] = a[j - 1] + a[j];
    }

    for (long long j = 1; j <= n; j++) {
        cout << a[j] << " ";
    }
}