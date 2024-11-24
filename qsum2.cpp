#include <iostream>
#include <vector>

using namespace std;

class LazySegmentTree {
    vector<long long> tree, lazy;
    int n;

    void build(const vector<long long>& array, int node, int start, int end) {
        if (start == end) {
            tree[node] = array[start];
        } else {
            int mid = (start + end) / 2;
            build(array, 2 * node + 1, start, mid);
            build(array, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRange(int l, int r, long long val, int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(l, r, val, 2 * node + 1, start, mid);
        updateRange(l, r, val, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long queryRange(int l, int r, int node, int start, int end) {
        if (start > end || start > r || end < l)
            return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        long long leftQuery = queryRange(l, r, 2 * node + 1, start, mid);
        long long rightQuery = queryRange(l, r, 2 * node + 2, mid + 1, end);
        return leftQuery + rightQuery;
    }

public:
    LazySegmentTree(const vector<long long>& array) {
        n = array.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(array, 0, 0, n - 1);
    }

    void updateRange(int l, int r, long long val) {
        updateRange(l, r, val, 0, 0, n - 1);
    }

    long long queryRange(int l, int r) {
        return queryRange(l, r, 0, 0, n - 1);
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    LazySegmentTree segTree(a);

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            segTree.updateRange(l - 1, r - 1, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << segTree.queryRange(l - 1, r - 1) << endl;
        }
    }

    return 0;
}