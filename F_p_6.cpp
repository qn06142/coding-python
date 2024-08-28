#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200005
int st[4 * MAXN], lazy[4 * MAXN];
int a[MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = -1; // -1 biểu thị không có giá trị cụ thể sau khi xây dựng
}

void propagate(int id, int l, int r) {
    if (lazy[id] != -1) {
        st[id] = lazy[id];
        if (l != r) {
            lazy[2 * id] = lazy[id];
            lazy[2 * id + 1] = lazy[id];
        }
        lazy[id] = -1;
    }
}

void update(int id, int l, int r, int u, int v, int color) {
    propagate(id, l, r);
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        lazy[id] = color;
        propagate(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, color);
    update(2 * id + 1, mid + 1, r, u, v, color);
}

int query(int id, int l, int r, int x) {
    propagate(id, l, r);
    if (l == r) return st[id];
    int mid = (l + r) / 2;
    if (x <= mid) return query(2 * id, l, mid, x);
    else return query(2 * id + 1, mid + 1, r, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    build(1, 1, n);
    fill(lazy, lazy + 4 * MAXN, -1);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, n, x) << '\n';
        }
    }
    
    return 0;
}
