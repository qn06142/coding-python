#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

using ll = long long;

bool check(const vector<pair<ll, ll>> &robots, ll t) {
    ll x_min = LLONG_MIN, x_max = LLONG_MAX;
    ll y_min = LLONG_MIN, y_max = LLONG_MAX;

    for (const auto &[x, y] : robots) {
        ll x_rot = x + y, y_rot = x - y;
        x_min = max(x_min, x_rot - t);
        x_max = min(x_max, x_rot + t);
        y_min = max(y_min, y_rot - t);
        y_max = min(y_max, y_rot + t);
    }

    return x_min <= x_max && y_min <= y_max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> robots(n);
    for (int i = 0; i < n; ++i) {
        cin >> robots[i].first >> robots[i].second;
    }

    ll left = 0, right = 2e18, ans = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(robots, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
