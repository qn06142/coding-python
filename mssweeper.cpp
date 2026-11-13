#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const double pi = acos(-1.0);

struct point {
    double x, y;

    bool operator<(const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

point a[maxn], hull[maxn * 2];

double cross(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, r;
    cin >> n >> r;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1);

    int m = 0;

    for (int i = 1; i <= n; i++) {
        while (m >= 2 && cross(hull[m - 1], hull[m], a[i]) <= 0) {
            m--;
        }

        hull[++m] = a[i];
    }

    int limit = m + 1;

    for (int i = n - 1; i >= 1; i--) {
        while (m >= limit && cross(hull[m - 1], hull[m], a[i]) <= 0) {
            m--;
        }

        hull[++m] = a[i];
    }

    if (n > 1) {
        m--;
    }

    double ans = 2 * pi * r;

    for (int i = 1; i <= m; i++) {
        ans += dist(hull[i], hull[i == m ? 1 : i + 1]);
    }

    cout << fixed << setprecision(4) << ans << '\n';
}