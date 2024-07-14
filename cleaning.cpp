#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr, int k) : n(arr.size()), k(k) {
        tree.resize(4 * n);
        max_tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void handle_query_set(int idx, int value) {
        update_set(idx - 1, value, 0, 0, n - 1);
    }

    void handle_query_wash(int l, int r) {
        if (k == 1) return; // No need to wash as k=1 doesn't change anything
        update_range(l - 1, r - 1, 0, 0, n - 1);
    }

    int handle_query_sum(int l, int r) {
        return query_sum(l - 1, r - 1, 0, 0, n - 1);
    }

private:
    int n, k;
    vector<int> tree, max_tree;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            max_tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        }
    }

    void update_set(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
            max_tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update_set(idx, value, 2 * node + 1, start, mid);
            } else {
                update_set(idx, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        }
    }

    void update_range(int l, int r, int node, int start, int end) {
        if (start > r || end < l || max_tree[node] == 0) return;
        if (start == end) {
            tree[node] /= k;
            max_tree[node] /= k;
        } else {
            int mid = (start + end) / 2;
            update_range(l, r, 2 * node + 1, start, mid);
            update_range(l, r, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        }
    }

    int query_sum(int l, int r, int node, int start, int end) {
        if (start > r || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left_sum = query_sum(l, r, 2 * node + 1, start, mid);
        int right_sum = query_sum(l, r, 2 * node + 2, mid + 1, end);
        return left_sum + right_sum;
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, k;
    cin >> n >> q >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree segment_tree(arr, k);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            segment_tree.handle_query_set(a, b);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            segment_tree.handle_query_wash(l, r);
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            cout << segment_tree.handle_query_sum(l, r) << '\n';
        }
    }
}

signed main() {
    solve();
    return 0;
}