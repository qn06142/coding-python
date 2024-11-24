#include <bits/stdc++.h>
using namespace std;
struct node {
    int cnt[20];
    int lazy;

    node () {
        memset(cnt, 0, sizeof cnt);
        lazy = 0;
    }
};

node seg[(int) 4e5 + 5];

void propagate(int l, int r, int id) {
    for(int i = 0; i < 20; i++) {
        if((seg[id].lazy >> i)& 1) {
            seg[id].cnt[i] = (r - l + 1) - seg[id].cnt[i];
        }
    }
    if(l < r) {
        seg[id * 2].lazy ^= seg[id].lazy;
        seg[id * 2 + 1].lazy ^= seg[id].lazy;
    }
    seg[id].lazy = 0;
}
node merge(node n1, node n2) {
    for(int i = 0; i < 20; i++) {
        n1.cnt[i] += n2.cnt[i];
    }
    return n1;
}
void update(int ql, int qr, int val, int l, int r, int id) {
    propagate(l, r, id);
    if(r < ql or l > qr) return;
    if(ql <= l and r <= qr) {
        seg[id].lazy ^= val;
        propagate(l, r, id);
        return;
    }
    int mid = (l + r) >> 1;
    update(ql, qr, val, l, mid, id * 2);
    update(ql, qr, val, mid + 1, r, id * 2 + 1);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}
node query(int ql, int qr, int l, int r, int id) {
    propagate(l, r, id);
    if(r < ql or qr < l) return node();
    if(ql <= l and r <= qr) return seg[id];
    int mid = (l + r) >> 1;
    return merge(query(ql, qr, l, mid, id * 2), query(ql, qr, mid + 1, r, id * 2 + 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, i, x, 1, n, 1);
    }

    cin >> q;
    while (q--) {
        int type, l, r, x;
        cin >> type >> l >> r;

        if (type == 1) {
            node tmp = query(l, r, 1, n, 1);
            long long ans = 0;
            for(int i = 0; i < 20; i++) {
                ans += 1LL * (1LL << i) * tmp.cnt[i];
            }
            cout << ans << '\n';
        } else if (type == 2) {
            cin >> x;
            update(l, r, x, 1, n, 1);
        }
    }

    return 0;
}
