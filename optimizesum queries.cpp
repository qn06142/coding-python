#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 200000;

int a[MAX_N + 1];
int b[MAX_N + 2];

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        b[l]++;
        b[r + 1]--;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
        ans += 1LL * a[i] * b[i];
    }

    cout << ans << endl;

    return 0;
}
