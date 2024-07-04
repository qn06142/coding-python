#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n), tree(4 * n, INT_MAX) {}

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, val, 2 * node + 1, start, mid);
            } else {
                update(idx, val, 2 * node + 2, mid + 1, end);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int L, int R, int node, int start, int end) {
        if (R < start || L > end) {
            return INT_MAX;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(L, R, 2 * node + 1, start, mid);
        int right_query = query(L, R, 2 * node + 2, mid + 1, end);
        return min(left_query, right_query);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int L, int R) {
        return query(L, R, 0, 0, n - 1);
    }

private:
    int n;
    vector<int> tree;
};

int min_additional_phones(int N, int D, const vector<int>& phones) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;  // The first phone rings initially

    SegmentTree segTree(N);
    segTree.update(0, 0);

    for (int i = 1; i < N; ++i) {
        int min_val = segTree.query(max(0, i - D), i - 1);
        if (phones[i] == 1) {
            dp[i] = min_val;
        } else {
            dp[i] = min_val + 1;
        }
        segTree.update(i, dp[i]);
    }

    return dp[N - 1];
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> phones(N);
    for (int i = 0; i < N; ++i) {
        cin >> phones[i];
    }

    int result = min_additional_phones(N, D, phones);
    cout << result << endl;

    return 0;
}
