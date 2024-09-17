#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--;  // Convert to 0-based index
        segs[i] = {l, r};
    }

    int q;
    cin >> q;
    vector<int> ord(q);
    for (int i = 0; i < q; ++i) {
        cin >> ord[i];
        ord[i]--;  // Convert to 0-based index
    }

    int l = 0, r = q + 1;
    
    while (r - l > 1) {
        int M = (l + r) / 2;
        vector<int> cur(n, 0);
        
        for (int i = 0; i < M; ++i) {
            cur[ord[i]] = 1;
        }

        vector<int> pr(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pr[i + 1] = pr[i] + cur[i];
        }

        bool ok = false;
        for (const auto& seg : segs) {
            if (pr[seg.second] - pr[seg.first] > (seg.second - seg.first) / 2) {
                ok = true;
                break;
            }
        }

        if (ok) {
            r = M;
        } else {
            l = M;
        }
    }

    if (r == q + 1) {
        r = -1;
    }

    cout << r << endl;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int T = 0; T < tc; ++T) {
        solve();
    }

    return 0;
}