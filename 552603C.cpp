#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        l--; r--; u--; v--;

        long long result = 0;

        for (int i = l; i <= r; ++i) {
            for (int j = u; j <= v; ++j) {
                result += abs(a[i] - a[j]);
            }
        }

        cout << result << '\n';
    }

    return 0;
}