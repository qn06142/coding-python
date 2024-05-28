#include<iostream>
#include<cmath>

using namespace std;
int divs[(int) 1e7 + 5];
long long pow(int m, int n, int mod) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= m;
        ans %= mod;
    }
    return ans;
}
void factorize(int m) {
    for (int i = 2; i <= sqrt(m); i++) { 
        int cnt = 0;
        while (m % i == 0) { 
            cnt ++;
            m = m/i; 
        } 
        divs[i] = max(cnt, divs[i]);
    } 
    if(m != 1) divs[m] = max(divs[m], 1);
}
int main() { 
    int mod = 1e9 + 7;
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        factorize(i);
    }
    long long ans = 1;
    for(int i = 1; i <= 1e7; i++) {
        ans *= pow(i, divs[i], mod);
        ans %= mod;

    }
    cout << ans;
}