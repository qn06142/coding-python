#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Segment {
    int left, right, index;
};

bool compareSegments(const Segment &a, const Segment &b) {
    if (a.left == b.left) return a.right > b.right;
    return a.left < b.left;
}

class SegmentTree {
public:
    vector<int> tree;
    int size;

    SegmentTree(int n) : size(n) {
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = size - 1;
        if (start == end) {
            tree[node] += val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(idx, val, 2 * node, start, mid);
            else update(idx, val, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int L, int R, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = size - 1;
        if (R < start || L > end) return 0;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        return query(L, R, 2 * node, start, mid) + query(L, R, 2 * node + 1, mid + 1, end);
    }
};

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    set<int> endpoints;

    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
        segments[i].index = i;
        endpoints.insert(segments[i].left);
        endpoints.insert(segments[i].right);
    }

    vector<int> coords(endpoints.begin(), endpoints.end());
    auto get_compressed = [&](int x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    for (auto &seg : segments) {
        seg.left = get_compressed(seg.left);
        seg.right = get_compressed(seg.right);
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> contains_count(n, 0);
    vector<int> is_contained_count(n, 0);
    SegmentTree segTree(coords.size());

    for (auto &seg : segments) {
        is_contained_count[seg.index] = segTree.query(seg.right, coords.size() - 1);
        segTree.update(seg.right, 1);
    }

    segTree = SegmentTree(coords.size());

    for (int i = n - 1; i >= 0; i--) {
        contains_count[segments[i].index] = segTree.query(segments[i].left, segments[i].right);
        segTree.update(segments[i].right, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << contains_count[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << is_contained_count[i] << " ";
    }
    cout << endl;

    return 0;
}