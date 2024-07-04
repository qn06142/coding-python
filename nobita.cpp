#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        data.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    int query(int l, int r, int val) {
        return query(1, 0, n - 1, l, r, val);
    }

private:
    int n;
    vector<int> data;

    void build(int node, int start, int end) {
        if (start == end) {
            data[node] = INT_MAX;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            data[node] = min(data[2 * node], data[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            data[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            data[node] = min(data[2 * node], data[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) {
            return -1; // out of range
        }
        if (start == end) {
            if (data[node] <= val) {
                return start;
            } else {
                return -1;
            }
        }
        if (l <= start && end <= r) {
            if (data[node] > val) {
                return -1;
            }
        }
        int mid = (start + end) / 2;
        int leftResult = query(2 * node, start, mid, l, r, val);
        if (leftResult != -1) {
            return leftResult;
        }
        return query(2 * node + 1, mid + 1, end, l, r, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    SegmentTree segmentTree(n);
    for (int i = 0; i < n; ++i) {
        segmentTree.update(i, heights[i]);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u; // 0-based index
            segmentTree.update(u, v);
        } else if (type == 2) {
            int u, v, val;
            cin >> u >> v >> val;
            --u; --v; // 0-based index
            int result = segmentTree.query(u, v, val);
            if (result == -1) {
                cout << "Skip\n";
            } else {
                cout << result + 1 << '\n'; // convert back to 1-based index
            }
        }
    }

    return 0;
}
