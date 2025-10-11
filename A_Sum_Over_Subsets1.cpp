#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    ll n;
    cin >> t >> n;

    int b = ceil(log2(n));
    int N = 1 << b;

    vector<ll> a(N, 0), res(N, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (t == 1) {
        // sum over submasks
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((j & i) == j) { // j is submask of i
                    res[i] += a[j];
                }
            }
        }
    } else {
        // sum over supermasks
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((j & i) == i) { // j is supermask of i
                    res[i] += a[j];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
