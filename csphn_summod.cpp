#include<iostream>
#include<cmath>
#include<numeric>
long long mod = 1e9 + 7;
using namespace std;
long long calc(long long n, long long p) {
    
    long long l = 1, ans = 0;
    while (l <= p) {
        long long r = n / (n / l);
        r = min(r, p);
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
    return ans;
}

long long f(long long n, long long p) {
    long long m = (n % mod) * (p % mod) % mod;
    long long res = (m - calc(n, p) + mod) % mod;
    if (res < 0) res += mod;
    return res;
}
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long out = (f(c, b) % mod - f(c, a - 1) % mod) % mod;
    if (out < 0) out += mod;
    cout << out;
}