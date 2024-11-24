#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size) {
        tree.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx > 0) {
            tree[idx] = max(tree[idx], val);
            idx -= idx & -idx;
        }
    }

    int query(int idx) {
        int max_val = 0;
        while (idx <= n) {
            max_val = max(max_val, tree[idx]);
            idx += idx & -idx;
        }
        return max_val;
    }
};

int dp[20005];
int a[2005];
int n, d;

int main() {
    cin >> n >> d;
    for(int i = 1; i <= n * 2; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> ind;
    for(int i = 1; i <= 2 * n; i++) {
        for(int j = i + 1; j <= 2 * n; j++) {
            if (abs(a[i] - a[j]) <= d) {
                ind.push_back({i, j});
            }
        }
    }

    sort(ind.begin(), ind.end(), greater<pair<int, int>>());

    int ans = 0;

    for(int bound = 1; bound <= 2 * n; bound++) {
        vector<pair<int, int> > c;
        FenwickTree f(2 * n);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < (int)ind.size(); ++i) {
            if (ind[i].first > bound || ind[i].second <= bound) continue;
            c.push_back(ind[i]);
        }
        for (int i = 0; i < (int)c.size(); i++) {
            int last = i;
            while (last < (int)c.size() && c[last].first == c[i].first) last++;
            last--;
            for (int iter1 = i; iter1 <= last; ++iter1) {
                int y = c[iter1].second;
                dp[iter1] = f.query(y + 1) + 1;
                ans = max(ans, dp[iter1]);
            }
            for (int iter1 = i; iter1 <= last; ++iter1) {
                int y = c[iter1].second;
                f.update(y, dp[iter1]);
            }
            i = last;
        }
    }
    cout << ans << '\n';
    return 0;
}