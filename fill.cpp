#include <bits/stdc++.h>
using namespace std;

struct rect {
    long double h, w, d, b;
    rect() {
        h = w = d = b = 0;
    }
};

long double calcvol(rect a, long double h) {
    if (h <= a.b) return 0;
    if (h >= a.b + a.h) return a.w * a.d * a.h;
    return a.w * a.d * (h - a.b);
}

int n;
long double v;
rect a[(int)1e5 + 5];

bool check(long double h) {
    long double volume = 0;
    for (int i = 1; i <= n; i++) {
        volume += calcvol(a[i], h);
    }
    return volume >= v; 
}

const long double eps = 1e-10; 

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
    }

    long double l = 0, r = 1e10, ans = 0; 
    while (r - l > eps) { 
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid; 
            ans = mid; 
        } else {
            l = mid; 
        }
    }

    cout << fixed << setprecision(6) << ans << '\n'; 
    return 0;
}