#include<bits/stdc++.h>
using namespace std;
#define maxn (int) 1e5 + 5

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    build();
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int i, v;
            cin >> i >> v;
            update(i, v);
        } else if(type == 2) {
           int l, r, k;
            cin >> l >> r >> k;
            if(k < 0) {
                cout << -1 << "\n";
                continue;
            }
            int sum = getsum(l, r);
            if(sum < k || (sum - k) % 2 != 0) {
                cout << -1 << "\n";
                continue;
            }
            // You can add the logic to find x and y here
        }
    }

    return 0;
}
