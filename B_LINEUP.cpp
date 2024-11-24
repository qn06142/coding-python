#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
const int MOD = 1e9 + 7;

class SegmentTree {
    vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val, int node, int node_lb, int node_ub) {
        if (node_lb == node_ub) {
            tree[node] = (tree[node] + val) % MOD;
            return;
        }
        int mid = (node_lb + node_ub) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * node, node_lb, mid);
        } else {
            update(idx, val, 2 * node + 1, mid + 1, node_ub);
        }
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
    }

    int query(int ql, int qr, int node, int node_lb, int node_ub) {
        if (ql > node_ub || qr < node_lb) {
            return 0;
        }
        if (ql <= node_lb && qr >= node_ub) {
            return tree[node];
        }
        int mid = (node_lb + node_ub) / 2;
        return (query(ql, qr, 2 * node, node_lb, mid) + query(ql, qr, 2 * node + 1, mid + 1, node_ub)) % MOD;
    }

    void update(int idx, int val) {
        update(idx, val, 1, 1, size);
    }

    int query(int ql, int qr) {
        return query(ql, qr, 1, 1, size);
    }
};

int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegmentTree segtree(n);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    segtree.update(1, 1); // Initial base case, dp[0] corresponds to an empty prefix

    stack<int> stk;
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && a[stk.top()] < a[i]) {
            stk.pop();
        }

        int left = (stk.empty() ? 1 : stk.top() + 1);
        dp[i] = segtree.query(left, i - 1) % MOD;
        segtree.update(i, dp[i]);

        stk.push(i);
    }

    cout << dp[n] << endl;

    return 0;
}
