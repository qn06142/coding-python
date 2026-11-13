#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), suf(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        suf[i] = min(a[i], suf[i + 1]);

    int p = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] > suf[i + 1]) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        for (int i = 1; i <= n; i++)
            cout << a[i] << (i == n ? '\n' : ' ');
        return 0;
    }

    if (n - p + 1 < k) {
        p = n - k + 1;
        sort(a.begin() + p, a.end());

        for (int i = 1; i <= n; i++)
            cout << a[i] << (i == n ? '\n' : ' ');
        return 0;
    }

    vector<int> s;
    vector<pair<int,int>> c;

    s.push_back(p);

    for (int i = p + 1; i <= n; i++)
        c.push_back({a[i], -i});

    sort(c.begin(), c.end());

    for (int i = 0; i < k - 1; i++)
        s.push_back(-c[i].second);

    sort(s.begin(), s.end());

    vector<int> v;
    for (int i : s)
        v.push_back(a[i]);

    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++)
        a[s[i]] = v[i];

    for (int i = 1; i <= n; i++)
        cout << a[i] << (i == n ? '\n' : ' ');
}
