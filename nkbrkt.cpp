#include<iostream>
#include<climits>
using namespace std;
const int inf = INT_MAX;
const int maxn = (int) 1e5 + 5;

struct node_ {
    long long sum, minpref;
};

node_ seg[4 * maxn];
int m, n;
long long a[maxn];

node_ calc(node_ l, node_ r) {
    node_ tmp;
    tmp.sum = l.sum + r.sum;
    tmp.minpref = min(l.minpref, l.sum + r.minpref);
    return tmp;
}
void build(int node = 1, int l = 1, int r = n) {
    if(l == r) seg[node] = {a[l], a[l]};
    else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        seg[node] = calc(seg[node * 2], seg[node * 2 + 1]);
    }
}

node_ getvalid(int x, int y, int node = 1, int l = 1, int r = n) {
    if(x < r or y < l) return {0, inf};
    if(l >= x and r <= y) return seg[node];
    int mid = (l + r) / 2;
    node_ L = getvalid(x, y, node * 2, l, mid);
    node_ R = getvalid(x, y, node * 2 + 1, mid + 1, r);
    return calc(L, R);
}

void update(int i, int node = 1, int l = 1, int r = n) {
    if(l == r) {
        int tmp = seg[node].sum;
        seg[node] = {-tmp, -tmp};
    } else {
        int mid = (l + r) / 2;
        if(mid >= i) update(i, node * 2, l, mid);
        else update(i, node * 2 + 1, mid + 1, r);
        seg[node] = calc(seg[node * 2], seg[node * 2 + 1]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        char tmp;
        cin >> tmp;
        if(tmp == '(') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
        build();
        for(int _ = 0; _ < m; _++) {
            int op;
            cin >> op;
            if(!op) {
                int pos;
                cin >> pos;
                update(pos);
            } else {
                int l, r;
                cin >> l >> r;
                node_ ans = getvalid(l, r);
                if(ans.sum == 0 and ans.minpref >= 0) {
                    cout << -1;
                } else {
                    cout << 0;
                }
            }
        }
    }
}