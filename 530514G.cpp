#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum, prefixSum, suffixSum, maxSum;
    Node(long long sum = 0, long long prefixSum = 0, long long suffixSum = 0, long long maxSum = 0) 
        : sum(sum), prefixSum(prefixSum), suffixSum(suffixSum), maxSum(maxSum) {}
};

const int MAXN = 1000005;
Node tree[4 * MAXN];
long long arr[MAXN];
int n, q;

Node combine(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    res.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    res.maxSum = max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = Node(arr[tl], arr[tl], arr[tl], max(arr[tl], 0LL));
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr) {
        tree[v] = Node(new_val, new_val, new_val, max(new_val, 0LL));
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return Node(0, 0, 0, 0); // return a node that represents an empty subarray
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    
    build(1, 1, n);
    
    while (q--) {
        int k;
        long long x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << query(1, 1, n, 1, n).maxSum << "\n";
    }
    
    return 0;
}