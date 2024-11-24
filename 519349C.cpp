#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, lim = 1e4;
int d[N], a[N], cnt[N], n, q;
pair<int, int> par[N];

#define d(x) d[x + N / 2]
#define par(x) par[x + N / 2]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= q;
    }

    memset(d, -1, sizeof(d));
    queue<int> qu;

    for (int i = 1; i <= n; i++) {
        if (d(a[i]) != -1) continue;
        par(a[i]) = {-1, i};
        d(a[i]) = 1;
        qu.push(a[i]);
    }

    while (!qu.empty()) {
        int x = qu.front(); qu.pop();
        if (x == 0) {
            cout << "YES\n";
            while (x != -1) {
                cnt[par(x).second]++;
                x = par(x).first;
            }
            for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
            cout << "\n";
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            int nx = x + a[i];
            if (nx >= -lim && nx <= lim && d(nx) == -1) {
                d(nx) = d(x) + 1;
                par(nx) = {x, i};
                qu.push(nx);
            }
        }
    }
    cout << "NO";
    return 0;
}
