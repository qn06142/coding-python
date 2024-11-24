#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")
const int MAXN = 2e5 + 5;
pair<int, int> st[4*MAXN];
int a[MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = make_pair(a[l], l);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        st[id] = make_pair(val, pos);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(id * 2, l, mid, pos, val);
    else
        update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

pair<int, int> get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return make_pair(0, 0);
    if (l >= u && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int p, v;
            cin >> p >> v;
            update(1, 1, n, p+1, v);
        } else {
            int l, r;
            cin >> l >> r;
            vector<pair<int, int>> bin;
            int res = 0;
            int val1 = -1, val2 = -1, val3 = -1;
            for (int _ = 0; _ < min(45, r - l + 1); _++) {
                pair<int, int> tmp = get(1, 1, n, l+1, r+1);
                bin.push_back(tmp);
                update(1, 1, n, tmp.second, 0);
                if (val1 == -1)
                    val1 = tmp.first;
                else if (val2 == -1)
                    val2 = tmp.first;
                else if (val3 == -1)
                    val3 = tmp.first;
                else {
                    val1 = val2;
                    val2 = val3;
                    val3 = tmp.first;
                }
                if (val3 != -1 && val1 < val2 + val3) {
                    res = val1 + val2 + val3;
                    break;
                }
            }
            cout << res << "\n";
            for (auto v : bin)
                update(1, 1, n, v.second, v.first);
        }
    }

    return 0;
}
