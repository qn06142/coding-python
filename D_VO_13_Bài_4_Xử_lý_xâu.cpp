#include <iostream>
using namespace std;

const int B1 = 59, B2 = 241, N = 1000100;

char a[N], b[N];
int n, m;
long long p1[N], p2[N], h1a[N], h2a[N], h1b[N], h2b[N];

int eq(int l, int r, int u, int v) {
    if ((h1a[r] - h1a[l - 1]) * p1[u] != (h1b[v] - h1b[u - 1]) * p1[l]) return 0;
    if ((h2a[r] - h2a[l - 1]) * p2[u] != (h2b[v] - h2b[u - 1]) * p2[l]) return 0;
    return 1;
}

char cmp(int l, int r, int u, int v) {
    int lo = 1, hi = min(r - l, v - u) + 1, mt = 0;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (eq(l, l + md - 1, u, u + md - 1)) mt = md, lo = md + 1;
        else hi = md - 1;
    }

    if (l + mt > r && u + mt > v) return '=';
    if (l + mt > r) return '<';
    if (u + mt > v) return '>';
    return a[l + mt] < b[u + mt] ? '<' : '>';
}
int main() {
    cin >> n >> m;
    scanf("%s%s", a + 1, b + 1);
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        p1[i] = p1[i - 1] * B1;
        p2[i] = p2[i - 1] * B2;
    }

    for (int i = 1; i <= n; ++i) {
        h1a[i] = h1a[i - 1] + p1[i - 1] * (a[i] - 'a');
        h2a[i] = h2a[i - 1] + p2[i - 1] * (a[i] - 'a');
    }
    for (int i = 1; i <= m; ++i) {
        h1b[i] = h1b[i - 1] + p1[i - 1] * (b[i] - 'a');
        h2b[i] = h2b[i - 1] + p2[i - 1] * (b[i] - 'a');
    }

    int q, l, r, u, v;
    cin >> q;
    while (q--) {
        cin >> l >> r >> u >> v;
        cout << cmp(l, r, u, v);
    }
}
