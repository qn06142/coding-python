#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_N = 2e5 + 10;

struct pair_ {
    int a, b;
    bool operator<(const pair_ &other) const {
        return a < other.a;
    }
} a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> a[i].a;
        for (int i = 0; i < n; i++)
            cin >> a[i].b;

        sort(a, a + n);

        priority_queue<int> stor;
        ll sum_ = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {

            if (stor.size() == k - 1) {
                ans = min(ans, (a[i].a) * (a[i].b + sum_));
            }

            sum_ += a[i].b;
            stor.push(a[i].b);

            if (stor.size() == k) {
                sum_ -= stor.top();
                stor.pop();
            }
        }

        cout << ans << '\n';
    }

    return 0;
}