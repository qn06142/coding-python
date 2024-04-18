#include<iostream>
#define maxn (int) 1e5 + 5
using namespace std;
int n;

long long seq[4 * maxn], a[maxn];
void build(int node = 1, int l = 1, int r = n) {
    if(l == r) {
        seq[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2 + 1, mid + 1, r);
        build(node * 2, l, mid);
        seq[node] = seq[node * 2] + seq[node * 2 + 1];
    }
}
void update(int x, int y, int node = 1, int l = 1, int r = n) {
    if(l == r) {
        seq[node] += y;

    } else {
        int mid = (l + r) / 2;
        if(x > mid) {
            //go right
            update(x, y, node * 2 + 1, mid + 1, r);
        } else {
            //go left
            update(x, y, node * 2, l, mid);
        }
        seq[node] = seq[node * 2] + seq[node * 2 + 1];
    }
}
long long getsum(int x, int y, int node = 1, int l = 1, int r = n) {
    //get sum from x to y
    if(x > r or y < l) {
        //not intersect
        return 0;
    } else {
        if(x <= l and y >= r) {
            //contains all
            return seq[node];
        }
        //intersect only
        int mid = (l + r) / 2;
        long long L = getsum(x, y, node * 2, l, mid);
        long long R = getsum(x, y, node * 2 + 1, mid + 1, r);
        return L + R;
    }
}
int main() {
    //http://csloj.ddns.net/problem/512
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i + 1];
    build();
    for(int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 1) {
            int i, x;
            cin >> i >> x;
            update(i, x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << getsum(u, v) << " ";
        }
    }
}