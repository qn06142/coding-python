#include <bits/stdc++.h>
using namespace std;

const int N = 507;
const int K = 2000;
const int MOD = 1e9 + 7;

int dp[N][K];

struct SegmentTree {
    vector<int> tree;
    int n;
    
    SegmentTree(int size) : n(size) {
        tree.resize(2 * n, 0);
    }

    void update(int pos, int value) {
        for (tree[pos += n] = value; pos > 1; pos >>= 1)
            tree[pos >> 1] = (tree[pos] + tree[pos ^ 1]) % MOD;
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = (res + tree[l++]) % MOD;
            if (r & 1) res = (res + tree[--r]) % MOD;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    dp[n][0] = 1;
    
    for (int i = n; i >= 1; i--) {
        SegmentTree segTree(k + 1);
        for (int j = 0; j <= k; j++) {
            segTree.update(j, dp[i][j]);
        }
        for (int j = 0; j <= k; j++) {
            int pos = n - i + 2;
            if (j > 0) dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
            int so_luong = pos - 1;
            if (j + so_luong <= k) {
                int sum = segTree.query(0, j + so_luong);
                dp[i-1][j+so_luong] = (dp[i-1][j+so_luong] + sum) % MOD;
            }
        }
    }
    
    cout << dp[1][k] << endl;
    return 0;
}
