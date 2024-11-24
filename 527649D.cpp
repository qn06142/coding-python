#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("arch=alderlake")

long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctzll(a | b); 
    a >>= __builtin_ctzll(a);
    do {
        b >>= __builtin_ctzll(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

#define int long long

int n, k, v;

int calc(int mid) {
    int ans = 0;
    for(int a = 1; a <= n; a++) {
        int g = gcd(a, k);
        if (k / g > mid) continue;
        int r = k / g;
        int right = min(mid - a, (long long) n);
        if(right >= 1) ans += right / r;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> v;
    int l = 2, r = 4e6, mid, ans;
    
    while(l <= r) {
        mid = (l + r) / 2;
        int cnt = calc(mid);
        if(cnt >= v) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    int pos = v - calc(ans - 1);
    for(int a = 1; a <= n; a++) {
        int b = ans - a;
        if(b <= 0 || b > n) continue;
        if((1LL * a * b) % k == 0) pos--;
        if(pos == 0) {
            cout << a << " " << b << "\n";
            return 0;
        }
    }
}
