#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], bit[MAXN];

void update(int x, int delta, int n) {
    for (; x <= n; x += x & (-x)) bit[x] += delta;
}

int query(int x) {
    int sum = 0;
    for (; x > 0; x -= x & (-x)) sum += bit[x];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        char type;
        cin >> type;
        if (type == 'S') {
            int i, k;
            cin >> i >> k;
            int delta = k - a[i];
            a[i] = k;
            update(i, delta, n);
        } else if (type == 'Q') {
            int i, j;
            cin >> i >> j;
            cout << query(j) - query(i - 1) << '\n';
        }
    }

    return 0;
}
