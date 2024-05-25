#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
vector<int> get_subset_sums(const vector<int>& a, int l, int r) {
    int len = r - l + 1;
    vector<int> res;

    // loop through all subsets
    for (int i = 0; i < (1 << len); ++i) {
        int sum = 0;
        for (int j = 0; j < len; ++j) {
            if (i & (1 << j)) {
                sum += a[l + j];
            }
        }
        res.push_back(sum);
    }

    return res;
}

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> left = get_subset_sums(a, 0, n / 2 - 1);
    vector<int> right = get_subset_sums(a, n / 2, n - 1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;
    for (int i : left) {
        int start_index = lower_bound(right.begin(), right.end(), x - i) - right.begin();
        int end_index = upper_bound(right.begin(), right.end(), x - i) - right.begin();
        ans += end_index - start_index;
    }

    cout << ans << endl;

    return 0;
}
