#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    bool operator<(Point const& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
    bool operator==(Point const& o) const {
        return x == o.x && y == o.y;
    }
};

__int128 cross128(const Point &a, const Point &b, const Point &c) {

    __int128 x1 = b.x - a.x;
    __int128 y1 = b.y - a.y;
    __int128 x2 = c.x - a.x;
    __int128 y2 = c.y - a.y;
    return x1 * y2 - x2 * y1;
}

__int128 dist2_128(const Point &a, const Point &b) {
    __int128 dx = (__int128)a.x - b.x;
    __int128 dy = (__int128)a.y - b.y;
    return dx*dx + dy*dy;
}

vector<Point> convex_hull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size();
    if (n <= 1) return pts;
    vector<Point> lower, upper;
    for (int i = 0; i < n; ++i) {
        while (lower.size() >= 2 && cross128(lower[lower.size()-2], lower.back(), pts[i]) <= 0)
            lower.pop_back();
        lower.push_back(pts[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        while (upper.size() >= 2 && cross128(upper[upper.size()-2], upper.back(), pts[i]) <= 0)
            upper.pop_back();
        upper.push_back(pts[i]);
    }

    lower.pop_back();
    upper.pop_back();
    vector<Point> hull = lower;
    hull.insert(hull.end(), upper.begin(), upper.end());
    return hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<Point> pts;
    pts.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        pts.push_back({xi, yi});
    }
    if (n == 0) {
        cout.setf(std::ios::fixed); cout<<setprecision(6)<<0.0<<'\n';
        return 0;
    }
    vector<Point> hull = convex_hull(pts);
    int m = hull.size();
    if (m == 1) {
        cout.setf(std::ios::fixed);
        cout<<setprecision(6)<<0.0<<'\n';
        return 0;
    }
    if (m == 2) {
        long double ans = sqrt((long double)dist2_128(hull[0], hull[1]));
        cout.setf(std::ios::fixed);
        cout<<setprecision(6)<< (double)ans <<'\n';
        return 0;
    }

    __int128 best = 0;
    int j = 1;
    for (int i = 0; i < m; ++i) {
        int ni = (i + 1) % m;

        while (true) {
            int nj = (j + 1) % m;
            __int128 cur = llabs((long long)cross128(hull[i], hull[ni], hull[j]));
            __int128 nxt = llabs((long long)cross128(hull[i], hull[ni], hull[nj]));
            if (nxt > cur) j = nj;
            else break;
        }

        __int128 cand = dist2_128(hull[i], hull[j]);
        if (cand > best) best = cand;
        cand = dist2_128(hull[ni], hull[j]);
        if (cand > best) best = cand;
    }
    long double ans_ld = sqrt((long double)best);
    cout.setf(std::ios::fixed);
    cout<<setprecision(6)<<(double)ans_ld<<'\n';
}