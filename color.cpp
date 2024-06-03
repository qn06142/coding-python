#include<bits/stdc++.h>
using namespace std;

bool check(int k, vector<int>& a) {
    unordered_map<int, int> m;
    int extra = 0;
    int n = a.size();

    for (int i = 0; i < k; i++) {
        m[a[i]]++;
        if (m[a[i]] > 1) {
            extra++;
        }
    }

    if (extra == 0) {
        return true;
    }

    for (int i = k; i < n; i++) {
        if (m[a[i - k]] > 1) {
            extra--;
        }
        m[a[i - k]]--;
        m[a[i]]++;
        if (m[a[i]] > 1) {
            extra++;
        }

        if (extra == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lo = 0, hi = n, ans = 0;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, a)) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
