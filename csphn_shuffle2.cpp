#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    if (!(cin >> n >> k >> x)) return 0;
    vector<int> I(x), M(x), J(x);
    for (int t = 0; t < x; ++t) {
        cin >> I[t] >> M[t] >> J[t];
    }
    vector<int> ans;
    ans.reserve(k);
    for (int p = 1; p <= k; ++p) {
        int pos = p; // hiện tại là vị trí p sau tất cả các phép
        // duyệt ngược các phép
        for (int t = x - 1; t >= 0; --t) {
            int i = I[t], m = M[t], j = J[t];
            // nếu pos nằm trong khối A được chèn (khoảng [j, j+m-1])
            if (pos >= j && pos <= j + m - 1) {
                pos = i + (pos - j);
            } else {
                int idx;
                if (pos < j) idx = pos;
                else idx = pos - m;
                if (idx < i) pos = idx;
                else pos = idx + m;
            }
        }
        ans.push_back(pos); // pos là nhãn ban đầu
    }
    for (int t = 0; t < (int)ans.size(); ++t) {
        if (t) cout << ' ';
        cout << ans[t];
    }
    cout << '\n';
    return 0;
}
