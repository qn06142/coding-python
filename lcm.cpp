#include<iostream>
#include<cmath>
#include<map>
using namespace std;
map<long long, long long> divs;
long long pow(long long m, long long n, long long mod) {
    long long ans = 1;
    for(long long i = 1; i <= n; i++) {
        ans *= m;
        ans %= mod;
    }
    return ans;
}
void factorize(long long m) {
    for (long long i = 2; i <= sqrt(m); i++) { 
        long long cnt = 0;
        while (m % i == 0) { 
            cnt ++;
            m = m/i; 
        } 
        divs[i] = max(cnt, divs[i]);
    } 
    if(m != 1) divs[m] = max(divs[m], 1LL);
}
int main() { 
    long long mod = 1e9 + 7;
    long long l, r;
    cin >> l >> r;
    for(long long i = l; i <= r; i++) {
        factorize(i);
    }
    long long ans = 1;
    for(long long i = 1; i <= 1e7; i++) {
        ans *= pow(i, divs[i], mod);
        ans %= mod;

    }
    cout << ans;
}