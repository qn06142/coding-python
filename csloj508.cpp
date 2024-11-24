#include<iostream>
#include<climits>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], tree[maxn * 4];
int n;
void build(int node = 1, int l = 1, int r = n) {
    if(l == r) {
        tree[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2 + 1, mid + 1, r);
        build(node * 2, l, mid);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
void update(int x, int y, int node = 1, int l = 1, int r = n) {
    if(l == r) {
        tree[node] = y;
    } else {
        int mid = (l + r) / 2;
        if(x > mid) {
            update(x, y, node * 2 + 1, mid + 1, r);
        } else {
            update(x, y, node * 2, l, mid);
        }
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
long long getval(int x, int y, int node = 1, int l = 1, int r = n) {
    if(x > r or y < l) return INT_MAX;
    else {
        if(x <= l and y >= r) return tree[node];
        int mid = (l + r) / 2;
        long long L = getval(x, y, node * 2, l, mid);
        long long R = getval(x, y, node * 2 + 1, mid + 1, r);
        return min(L, R);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << getval(u, v) << " ";
    }
}