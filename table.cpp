#include<bits/stdc++.h>
using namespace std;

const int B = 700;
const int MAXN = 505;
struct Data {
    int x, y, u, v, w;
    Data(int x=0, int y=0, int u=0, int v=0, int w=0) : x(x), y(y), u(u), v(v), w(w) {}
};

int a[MAXN][MAXN], p[MAXN][MAXN], d[MAXN][MAXN];
vector<Data> upd;

void rebuild(int n, int m) {
    memset(d, 0, sizeof(d));
    for(auto& i : upd) {
        d[i.x][i.y] += i.w;
        d[i.x][i.v + 1] -= i.w;
        d[i.u + 1][i.y] -= i.w;
        d[i.u + 1][i.v + 1] += i.w;
    }
    upd.clear();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            a[i][j] += d[i][j];
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, Q;
    cin >> n >> m >> Q;
    
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }
    for(int _ = 0; _ < Q; ++_) {
        if(Q % B == 0) {
            rebuild(n, m);
        }
        int t;
        cin >> t;
        if(t == 1) {
            int x, y, u, v, w;
            cin >> x >> y >> u >> v >> w;
            upd.push_back(Data(x, y, u, v, w));
        } else {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            int ans = p[u][v] - p[x - 1][v] - p[u][y - 1] + p[x - 1][y - 1];
            for(auto& i : upd) {
                i.x = max(i.x, x);
                i.y = max(i.y, y);
                i.u = min(i.u, u);
                i.v = min(i.v, v);
                if(i.x > i.u || i.y > i.v) {
                    continue;
                }
                ans += (i.u - i.x + 1) * (i.v - i.y + 1) * i.w;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
