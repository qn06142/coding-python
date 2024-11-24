#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9;

int len(int l, int r) {
    int len = 1;
    while(l * 2 <= r) {
        l *= 2;
        len ++;
    }
    return len;
}
int pw2 (int x) {
    int ans = 1;
    for(int i  = 1; i <= x; i++) {
        ans *= 2;
    }
    return ans;
}
signed main() {
    int l, r;
    cin >> l >> r;
    int mx = len(l, r);
    int point  = r / pw2(mx - 1);
    int ans = (point - l + 1) % mod;
    point = r / pw2 (mx -  2) / 3;
    if (point >= l) ans  = (ans + ((point - l + 1) % mod * (mx - 1) % mod)) % mod;
    cout << mx << ' ' << ans << endl;
}