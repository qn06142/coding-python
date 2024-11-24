#include<bits/stdc++.h>
#define minn (int) 1e6 + 5
using namespace std;
int n;

long long seq[4 * minn], a[minn];
void build(int node = 1, int l = 1, int r = n) {
    if(l == r) {
        seq[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2 + 1, mid + 1, r);
        build(node * 2, l, mid);
        seq[node] = min(seq[node * 2], seq[node * 2 + 1]);
    }
}
void update(int x, int y, int node = 1, int l = 1, int r = n) {
    if(l == r) {
        seq[node] = y;

    } else {
        int mid = (l + r) / 2;
        if(x > mid) {
            //go right
            update(x, y, node * 2 + 1, mid + 1, r);
        } else {
            //go left
            update(x, y, node * 2, l, mid);
        }
        seq[node] = min(seq[node * 2], seq[node * 2 + 1]);
    }
}
long long getmin(int x, int y, int node = 1, int l = 1, int r = n) {
    //get sum from x to y
    if(x > r or y < l) {
        //not intersect
        return INT_MAX;
    } else {
        if(x <= l and y >= r) {
            //contains all
            return seq[node];
        }
        //intersect only
        int mid = (l + r) / 2;
        long long L = getmin(x, y, node * 2, l, mid);
        long long R = getmin(x, y, node * 2 + 1, mid + 1, r);
        return min(L, R);
    }
}
int main() {
    //http://csloj.ddns.net/problem/509
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i + 1];
    build();
    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << getmin(u, v) << '\n';

    }
}