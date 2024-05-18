#include<iostream>
#define maxn (int) 1e5 + 5
using namespace std;
int n;

long long seq[4 * maxn], a[maxn], divs[(int) 1e6 + 5];
void calcdivs() {
    for(int i = 1; i <= 1e6; i++) {
        for(int j = i; j <= 1e6; j += i) {
            divs[j] ++;
        }
    }
}
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
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i + 1];
    calcdivs();
    build();
    //cout << divs[10] << endl;;
    for(int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 1) {
            int l, r;
            cin >> l >> r;
            for(int i = l; i <= r; i++) {
                update(i, divs[a[i]]);
            }
        } else {
            int u, v;
            cin >> u >> v;
            cout << getsum(u, v) << " ";
        }
    }
}