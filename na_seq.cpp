#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 3e5 + 5;

int pref[MAXN];
int a[MAXN];
int bit[(int) 1e7];

void update(int idx, int v, int n) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += v;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    vector<int> values;
    values.push_back(0); 
    for (int i = 1; i <= n; i++) {
        values.push_back(pref[i]);
        values.push_back(pref[i] - l);
        values.push_back(pref[i] - r);
        values.push_back(pref[i] + l);
        values.push_back(pref[i] + r);
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto get_compressed = [&](int x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin() + 1;
    };

    int ans = 0;

    int max_idx = values.size();
    update(get_compressed(0), 1, max_idx); 

    for (int i = 1; i <= n; i++) {

        int low1 = get_compressed(pref[i] - r);
        int high1 = get_compressed(pref[i] - l);

        ans += range_query(low1, high1);

        int low2 = get_compressed(pref[i] + l);
        int high2 = get_compressed(pref[i] + r);

        ans += range_query(low2, high2);
        if (low1 <= high2 && low2 <= high1) {
            int overlapLow = max(low1, low2);
            int overlapHigh = min(high1, high2);
            ans -= range_query(overlapLow, overlapHigh);
        }
        update(get_compressed(pref[i]), 1, max_idx);
    }

    cout << ans << '\n';
    return 0;
}