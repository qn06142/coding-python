#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int bit[maxn];

void update(int i, int v) {
    while (i < maxn) {
        bit[i] += v;
        i += i & -i;
    }
}

int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int find_median(int total) {
    int l = 1, r = maxn - 1, ans = -1;
    int median_pos = (total + 1) / 2; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(mid) >= median_pos) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int med(int m) {
    update(m, -1); 
    int tot = query(maxn - 1);
    int result = find_median(tot);
    update(m, 1); 
    return result;
}
map<int, int> mapping;
int main() {
    #ifdef ONLINE_JUDGE
    freopen(("MEDIAN.inp"), "r", stdin);
    freopen(("MEDIAN.out"), "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cmp(a + 1, a + 1 + n);
    sort(cmp.begin(), cmp.end());
    for (int i = 1; i <= n; i++) {
        mapping[lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1] = a[i];
        a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
        update(a[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << mapping[med(a[i])] << ' ';
    }
    return 0;
}