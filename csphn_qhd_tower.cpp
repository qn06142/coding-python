#include <bits/stdc++.h>
#define maxn (int)1e6 + 5
using namespace std;
int n;

pair<long long, int> seq[4 * maxn], a[maxn];
void update(int ind, int x, long long y, int node = 1, int l = 1, int r = 1e6) {
    if (l == r) {
        if (seq[node].first <= y) {
            seq[node].first = y;
            seq[node].second = ind;
        }
    } else {
        int mid = (l + r) / 2;
        if (x > mid) {
            // go right
            update(ind, x, y, node * 2 + 1, mid + 1, r);
        } else {
            // go left
            update(ind, x, y, node * 2, l, mid);
        }
        seq[node] = max(seq[node * 2], seq[node * 2 + 1]);
    }
}
pair<long long, int> getmax(int x, int y, int node = 1, int l = 1, int r = 1e6) {
    // get sum from x to y
    if (x > r or y < l) {
        // not intersect
        return make_pair(0, -1);
    } else {
        if (x <= l and y >= r) {
            // contains all
            return seq[node];
        }
        // intersect only
        int mid = (l + r) / 2;
        pair<long long, int> L = getmax(x, y, node * 2, l, mid);
        long long R = getmax(x, y, node * 2 + 1, mid + 1, r).first;
        return make_pair(max(L.first, R), L.second);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<array<int, 4>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
    }

    sort(a.begin() + 1, a.end());

    // a[i][0] - a
    // a[i][1] - b
    // a[i][2] - h

    vector<long long> dp(n + 1, 0);
    vector<int> pre(n + 1, -1);

    long long res = 0;
    int mx = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = getmax(1, a[i][0]).first + a[i][2];
        pre[i] = getmax(1, a[i][0]).second;
        update(i, a[i][1], dp[i]);
        if (dp[i] > res) {
            res = dp[i];
            mx = i;
        }
    }


    cout << res;

    return 0;
}
