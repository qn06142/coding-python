#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
pair<int, int> tree[4 * MAXN]; 
int n, q;
int a[MAXN];

pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
    vector<int> vals = {left.first, left.second, right.first, right.second};
    sort(vals.begin(), vals.end());
    return {vals[0], vals[1]};
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {a[start], INT_MAX}; 
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

pair<int, int> query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return {INT_MAX, INT_MAX}; 
    }
    if (start >= l && end <= r) {
        return tree[node]; 
    }
    int mid = (start + end) / 2;
    pair<int, int> left = query(2 * node, start, mid, l, r);
    pair<int, int> right = query(2 * node + 1, mid + 1, end, l, r);
    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n - 1); 

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--; 

        pair<int, int> res = query(1, 0, n - 1, l, r);

        if (res.second == INT_MAX) {
            cout << -1 << '\n'; 
        } else {
            cout << res.second << '\n'; 
        }
    }

    return 0;
}