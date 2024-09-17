#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1234567891;

struct SegmentTree {
    int n;
    vector<long long> tree, lazy;

    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node] % MOD;
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long k) {
        propagate(node, start, end);
        if (start > r || end < l)
            return;
        if (start >= l && end <= r) {
            lazy[node] += k;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, k);
        update(node * 2 + 1, mid + 1, end, l, r, k);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }

    long long query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return tree[node] % MOD;
        int mid = (start + end) / 2;
        long long q1 = query(node * 2, start, mid, l, r);
        long long q2 = query(node * 2 + 1, mid + 1, end, l, r);
        return (q1 + q2) % MOD;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    SegmentTree segTree(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        segTree.update(1, 1, n, i, i, a[i] * i % MOD);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(1, 1, n, l, r) << '\n';
        } else if (type == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            segTree.update(1, 1, n, l, r, k);
        }
    }
    return 0;
}
