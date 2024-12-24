#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> sa = a;
    sort(sa.begin(), sa.end());

    vector<long long> psa(sa.size() + 1);
    partial_sum(sa.begin(), sa.end(), psa.begin() + 1);

    auto calc = [&](int x) {
        int ind = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
        long long left_sum = static_cast<long long>(x) * ind - psa[ind];
        long long right_sum = (psa.back() - psa[ind]) - static_cast<long long>(x) * (n - ind);
        return left_sum + right_sum;
    };

    long long min_dist = calc(0);
    vector<int> result_positions;
    int max_ = *max_element(a.begin(), a.end());
    int min_ = *min_element(a.begin(), a.end());
    int mid = (max_ + min_) / 2;

    int l = max(mid - 100000, min_);
    int r = min(mid + 100000, max_);
    vector<int> count;

    for (int x = l; x < r; ++x) {
        long long total_dist = calc(x);
        if (total_dist < min_dist) {
            min_dist = total_dist;
            count = {x};
        } else if (total_dist == min_dist) {
            count.push_back(x);
        }
    }

    cout << count.size() << endl;
    for (int x : count) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

