#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long sum, val;
};

struct SegmentTree {
private:
    vector<Node> tree;
    int n;

    void propagate(int id, int l, int r) {
        long long &x = tree[id].val;
        if (x != -1) {
            int m = (l + r) / 2;
            tree[2 * id].val = tree[2 * id + 1].val = x;
            tree[2 * id].sum = (m - l + 1) * x;
            tree[2 * id + 1].sum = (r - m) * x;
            x = -1;
        }
    }

    void update(int id, int l, int r, int i, int j, long long x) {
        if (l > j || r < i) return;
        if (i <= l && r <= j) {
            tree[id].val = x;
            tree[id].sum = (r - l + 1) * x;
            return;
        }
        propagate(id, l, r);
        int m = (l + r) / 2;
        update(2 * id, l, m, i, j, x);
        update(2 * id + 1, m + 1, r, i, j, x);
        tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
    }

    long long query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return tree[id].sum;
        propagate(id, l, r);
        int m = (l + r) / 2;
        return query(2 * id, l, m, i, j) + query(2 * id + 1, m + 1, r, i, j);
    }

public:
    SegmentTree(int n) : n(n) {
        tree.assign(4 * n + 1, {0, -1});
    }

    void update(int i, int j, long long x) {
        update(1, 1, n, i, j, x);
    }

    long long query(int i, int j) {
        return query(1, 1, n, i, j);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SegmentTree segTree(n);

    for (int i = 0; i < q; ++i) {
        int r;
        long long p;
        cin >> r >> p;

        int lo = 1, hi = r - 1, l = r;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long aMid = segTree.query(mid, mid);
            long long x = (r - mid + 1) * aMid - segTree.query(mid, r);

            if (x <= p) {
                l = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        long long aL = segTree.query(l, l);
        p -= (r - l + 1) * aL - segTree.query(l, r);

        long long aNew = aL + p / (r - l + 1);
        int m = l + p % (r - l + 1) - 1;
        segTree.update(l, m, aNew + 1);
        segTree.update(m + 1, r, aNew);
    }

    for (int i = 1; i <= n; ++i)
        cout << segTree.query(i, i) << ' ';

    return 0;
}
