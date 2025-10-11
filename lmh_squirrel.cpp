#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<long long> tops;

    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        long long x = h[i];

        auto it = upper_bound(tops.begin(), tops.end(), x);
        if (it == tops.end()) {

            tops.push_back(x);
            ans.emplace_back();
            ans.back().push_back(i + 1); 
        } else {
            int pos = int(it - tops.begin());
            tops[pos] = x;
            ans[pos].push_back(i + 1);
        }
    }

    cout << ans.size() << '\n';
    for (auto &p : ans) {
        cout << p.size();
        for (int idx : p) cout << ' ' << idx;
        cout << '\n';
    }

}