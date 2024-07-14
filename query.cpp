#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define int long long

int n, q;
int a[MAXN];
int segTree[4 * MAXN], lazy[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        segTree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > end || start > r || end < l)
        return;

    if (start >= l && end <= r) {
        segTree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int queryRange(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l)
        return 0;

    if (lazy[node] != 0) {
        segTree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start >= l && end <= r)
        return segTree[node];

    int mid = (start + end) / 2;
    int p1 = queryRange(2 * node, start, mid, l, r);
    int p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build(1, 1, n);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v, x;
            cin >> u >> v >> x;
            updateRange(1, 1, n, u, v, x);
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            cout << queryRange(1, 1, n, u, v) << "\n";
        }
    }
    
    return 0;
}
