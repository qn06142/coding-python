#include<iostream>
#include<cmath>
#include<numeric>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long mod = 1e9 + 7;
    long long l = 1, ans = 0;
    while (l <= n) {
        long long r = n / (n / l);
        r = min(r, n);
        long long tmp =  l + r;
        long long tmp1 = r - l + 1;
        if(tmp % 2 == 0) {
            tmp /= 2;
        } else {
            tmp1 /= 2;
        }
        tmp %= mod;
        tmp1 %= mod;
        ans += (tmp1 * tmp) % mod * (n / l);
        ans = ans % mod;
        l = r + 1;
    }
    cout << ans;
}