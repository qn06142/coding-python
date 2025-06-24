#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt1 = 0;
    for (int x : a) {
        if (x == 1) cnt1++;
    }
    if (cnt1 > 0) {

        cout << (n - cnt1) << '\n';
        return 0;
    }

    const int INF = 1e9;
    int best_len = INF;
    for (int i = 0; i < n; i++) {
        int g = a[i];
        if (g == 1) {
            best_len = 1;
            break;
        }
        for (int j = i + 1; j < n; j++) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                best_len = min(best_len, j - i + 1);
                break;
            }
        }
    }

    if (best_len == INF) {

        cout << -1 << '\n';
    } else {

        long long result = (long long)(best_len - 1) + (n - 1);
        cout << result << '\n';
    }
}