#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    s = ' ' + s + ' ';

    vector<int> d(n + 5), l(n + 5), q(n + 5);

    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1];
        d[i] = d[i - 1];
        q[i] = q[i - 1];
        if (s[i] == 'L')
            l[i]++;
        else if (s[i] == 'Q')
            q[i]++;
        else
            d[i]++;
    }

    int el = 1, eq = 1, ed = 1, ans = 1e9;

    for (int i = 1; i <= n; i++) {
        while (l[el] - l[i - 1] < k) {
            el++;
            if (el == n + 1) break;
        }
        eq = max(eq, el);
        while (q[eq] - q[el - 1] < k) {
            eq++;
            if (eq == n + 1) break;
        }
        ed = max(eq, ed);
        while (d[ed] - d[eq - 1] < k) {
            ed++;
            if (ed == n + 1) break;
        }
        if (ed == n + 1 || eq == n + 1 || el == n + 1) break;
        ans = min(max({el, eq, ed}) - i - 3 * k + 1, ans);
    }

    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;

    return 0;
}