#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int tree[2 * N], n;

void update(int k, int x) {
    k += n;
    tree[k] = x;
    k >>= 1;
    while (k >= 1) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
        k >>= 1;
    }
}

int query(int x) {
    if (tree[1] < x) return -1;
    int k = 1;
    while (k < n) {
        if (tree[2 * k] >= x) k <<= 1;
        else k = k * 2 + 1;
    }
    return k - n;
}

void solve() {
    int m;
    cin >> n >> m;
    int nn = n;
    n = ceil(log2(n * 1.0));
    n = 1 << n;

    for (int i = 0; i < nn; ++i) {
        int x;
        cin >> x;
        update(i, x);
    }

    while (m--) {
        int x;
        cin >> x;
        int i = query(x);
        cout << (i + 1) << " ";
        if (i >= 0) {
            int y = tree[i + n] - x;
            update(i, y);
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
