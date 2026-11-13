#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum = 0, pref = 0, suf = 0, msum = 0;
    Node(long long val = 0) {
        sum = val;
        pref = max(0LL, val);
        suf = max(0LL, val);
        msum = max(0LL, val);
    }
};

const int MAXN = 2005;
Node tree[4 * MAXN];
long long arr[MAXN];
vector<pair<int, int>> row[MAXN];
int n, m;

Node combine(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.pref = max(left.pref, left.sum + right.pref);
    res.suf = max(right.suf, right.sum + left.suf);
    res.msum = max({left.msum, right.msum, left.suf + right.pref});
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        arr[tl] = 0;
        tree[v] = Node(0);
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, long long add_val) {
    if (tl == tr) {
        arr[tl] += add_val;
        tree[v] = Node(arr[tl]);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, add_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, add_val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    vector<tuple<int, int, int>> stor;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        stor.push_back({x, y, 1});
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        stor.push_back({x, y, -1});
    }
    int a, b;
    cin >> a >> b;
    for(auto [x, y, type] : stor) {
        row[x + 1001].push_back({y + 1001, (type == 1 ? a : -b)});
    }
    long long ans = 0;
    for(int i = 1; i <= 2001; i++) {
        if (row[i].empty()) continue;
        build(1, 1, 2001);
        for(int j = i; j <= 2001; j++) {
            if (row[j].empty()) continue;
            for(auto [y, w] : row[j]) {
                update(1, 1, 2001, y, w);
            }
            ans = max(ans, tree[1].msum);
        }
    }
    cout << ans;
}