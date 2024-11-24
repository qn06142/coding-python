#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e6 + 5;

struct SegmentTree {
    vector<int> min_tree, max_tree;
    int n;

    SegmentTree(int size) : n(size) {
        min_tree.assign(4 * n, INF);
        max_tree.assign(4 * n, -INF);
    }

    void build(const vector<int>& heights, int node, int start, int end) {
        if (start == end) {
            min_tree[node] = heights[start];
            max_tree[node] = heights[start];
        } else {
            int mid = (start + end) / 2;
            build(heights, 2 * node, start, mid);
            build(heights, 2 * node + 1, mid + 1, end);
            min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
            max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
        }
    }

    int query_min(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INF;
        }
        if (l <= start && end <= r) {
            return min_tree[node];
        }
        int mid = (start + end) / 2;
        int left_min = query_min(2 * node, start, mid, l, r);
        int right_min = query_min(2 * node + 1, mid + 1, end, l, r);
        return min(left_min, right_min);
    }

    int query_max(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return -INF;
        }
        if (l <= start && end <= r) {
            return max_tree[node];
        }
        int mid = (start + end) / 2;
        int left_max = query_max(2 * node, start, mid, l, r);
        int right_max = query_max(2 * node + 1, mid + 1, end, l, r);
        return max(left_max, right_max);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> heights(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }

    SegmentTree seg_tree(n);
    seg_tree.build(heights, 1, 1, n);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int min_val = seg_tree.query_min(1, 1, n, l, r);
        int max_val = seg_tree.query_max(1, 1, n, l, r);
        cout << max_val - min_val << "\n";
    }

    return 0;
}
