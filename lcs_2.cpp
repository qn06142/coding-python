#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Compressed2DBIT {
private:
    int n, m;
    vector<vector<int>> bit;

    inline int lsb(int x) {
        return x & -x;
    }

public:
    Compressed2DBIT(int n, int m) : n(n), m(m) {
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += lsb(i)) {
            for (int j = y; j <= m; j += lsb(j)) {
                bit[i][j] = max(bit[i][j], val);
            }
        }
    }

    int query(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= lsb(i)) {
            for (int j = y; j > 0; j -= lsb(j)) {
                res = max(res, bit[i][j]);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), b(m + 1);
        vector<int> cmp;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cmp.push_back(a[i]);
            cmp.push_back(a[i] * 2);
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            cmp.push_back(b[i]);
            cmp.push_back(b[i] * 2);
        }

        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

        vector<int> a2(n + 1);
        for (int i = 1; i <= n; i++) {
            a2[i] = lower_bound(cmp.begin(), cmp.end(), a[i] * 2) - cmp.begin() + 1;
            a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
        }
        for (int i = 1; i <= m; i++) {
            b[i] = lower_bound(cmp.begin(), cmp.end(), b[i]) - cmp.begin() + 1;
        }

        int compressedSize = cmp.size();
        Compressed2DBIT bit(compressedSize, m);

        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            vector<pair<pair<int, int>, int>> updates;
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j]) {
                    int prev_max = bit.query(a[i], j - 1);
                    int curr = prev_max + 1;
                    updates.emplace_back(make_pair(a2[i], j), curr);
                    ans = max(ans, curr);
                    dp[i][j] = curr;
                }
            }
            for (auto& upd : updates) {
                bit.update(upd.first.first, upd.first.second, upd.second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
