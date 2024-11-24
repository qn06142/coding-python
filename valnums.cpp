#include <bits/stdc++.h>
using namespace std;
int mn[(int) 1e6 + 1][2], mx[(int) 1e6 + 1][2], prefix[(int) 1e6 + 5];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;


    cin >> n >> m >> s;
    s = '?' + s;
    for (int i = 1; i <= n; ++ i)
    {
        prefix[i] = prefix[i - 1] + (s[i] == '+' ? 1 : -1);
        mx[i][0] = max(mx[i - 1][0], prefix[i]);
        mn[i][0] = min(mn[i - 1][0], prefix[i]);
    }
    mn[n + 1][1] = mx[n + 1][1] = prefix[n];
    for (int i = n; i >= 1; -- i)
    {
        mx[i][1] = max(mx[i + 1][1], prefix[i]);
        mn[i][1] = min(mn[i + 1][1], prefix[i]);
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int l1 = mn[l-1][0];
        int r1 = mx[l-1][0];
        int l2 = mn[r+1][1] - (prefix[r] - prefix[l-1]);
        int r2 = mx[r+1][1] - (prefix[r] - prefix[l-1]);
        cout << max(r1, r2) - min(l1, l2) + 1 << "\n";
    }

    return 0;
}
