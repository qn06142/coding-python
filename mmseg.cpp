#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

long long a[maxn];
long long mnl[maxn], mxl[maxn];
long long mnr[maxn], mxr[maxn];

long long calc(int l, int m, int r, unsigned __int128 x) {
    int nl = m - l + 1;
    int nr = r - m;

    mnl[0] = mxl[0] = a[m];
    for (int i = 1; i < nl; i++) {
        mnl[i] = min(mnl[i - 1], a[m - i]);
        mxl[i] = max(mxl[i - 1], a[m - i]);
    }

    mnr[0] = mxr[0] = a[m + 1];
    for (int i = 1; i < nr; i++) {
        mnr[i] = min(mnr[i - 1], a[m + 1 + i]);
        mxr[i] = max(mxr[i - 1], a[m + 1 + i]);
    }

    long long ans = 0;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

    for (int i = 0; i < nl; i++) {
        while (p1 < nr && mnr[p1] >= mnl[i])
            p1++;

        while (p2 < nr && mxr[p2] <= mxl[i])
            p2++;

        if ((unsigned __int128)mnl[i] * mxl[i] <= x)
            ans += min(p1, p2);

        unsigned __int128 b3 = x / mnl[i];

        while (p3 < nr && (unsigned __int128)mxr[p3] <= b3)
            p3++;

        int up = min(p1, p3);
        if (up > p2)
            ans += up - p2;

        unsigned __int128 b4 = x / mxl[i];

        while (p4 < nr && (unsigned __int128)mnr[p4] > b4)
            p4++;

        int lo = max(p1, p4);
        if (p2 > lo)
            ans += p2 - lo;
    }

    int q1 = 0, q2 = 0;

    for (int j = 0; j < nr; j++) {
        while (q1 < nl && mnl[q1] > mnr[j])
            q1++;

        while (q2 < nl && mxl[q2] < mxr[j])
            q2++;

        if ((unsigned __int128)mnr[j] * mxr[j] <= x)
            ans += min(q1, q2);
    }

    return ans;
}

long long solve(int l, int r, unsigned __int128 x) {
    if (l > r)
        return 0;

    if (l == r)
        return (unsigned __int128)a[l] * a[l] <= x;

    int m = (l + r) / 2;

    long long ans = solve(l, m, x);
    ans += solve(m + 1, r, x);
    ans += calc(l, m, r, x);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--) {
        long long x;
        cin >> x;
        cout << solve(1, n, (unsigned __int128)x) << '\n';
    }
}