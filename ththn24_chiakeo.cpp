#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAX_N = 200000;
const int MAX_A = 500000;

struct LazySegmentTree {
    struct LazyUpdate {
        int x;        
        long long v;  
    };

    vector<long long> tree;
    vector<vector<LazyUpdate>> lazy;
    vector<int> a;
    int n;
    bool isDivisible(int i, int x) {
        return a[i] % x == 0;
    }
    LazySegmentTree(int size, const vector<int>& arr) : n(size), a(arr) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, vector<LazyUpdate>());
    }

    void propagate(int node, int start, int end) {
        if (!lazy[node].empty()) {
            for (const auto& upd : lazy[node]) {
                int x = upd.x;
                long long v = upd.v;

                for (int i = start; i <= end; i++) {
                    if (isDivisible(i, x)) {
                        tree[node] += v * (end - start + 1);
                    }
                }
            }

            if (start != end) { 
                for (const auto& upd : lazy[node]) {
                    lazy[2 * node].push_back(upd);
                    lazy[2 * node + 1].push_back(upd);
                }
            }
            lazy[node].clear(); 
        }
    }

    void update(int node, int start, int end, int l, int r, int x, long long v) {
        propagate(node, start, end);
        if (start > r || end < l) return; 
        if (start >= l && end <= r) {    
            lazy[node].push_back({x, v});
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, x, v);
        update(2 * node + 1, mid + 1, end, l, r, x, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > r || end < l) return 0; 
        if (start >= l && end <= r) return tree[node]; 

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    LazySegmentTree segTree(N, a);

    while (Q--) {
        int l, r, x;
        long long v;
        cin >> l >> r >> x >> v;

        segTree.update(1, 1, N, l, r, x, v);
    }
    segTree.query(1, 1, N, 1, N);
    for (int i = 1; i <= N; i++) {
        cout << segTree.query(1, 1, N, i, i) << " ";
    }
    cout << "\n";

    return 0;
}