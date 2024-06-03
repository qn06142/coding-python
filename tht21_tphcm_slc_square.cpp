#include<iostream>
#include<math.h>
#include<climits>
#include<unordered_map>
#include<bit>
#include<algorithm>
#include<numeric>
#include<cmath>

using namespace std;

unordered_map<long long, long long> factors;
void primeFactorization(int n) {
    for(int i = 2; i * i <= n; i++) {
        long long cnt = 0;
        while(n % i == 0) {
            cnt++;
            n /= i;
        }
        factors[i] = max(factors[i], cnt);
    }
    if (n > 1) {
        factors[n] = max(factors[n], 1LL);
    }
}

long long pow(long long base, long long exp) {
    long long ans = 1;
    for(int i = 1; i <= exp; i++) ans = (ans * base);
    return ans;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    primeFactorization(a);
    primeFactorization(b);
    primeFactorization(c);
    long long ans = 1;
    for(auto i:factors) {
        ans = ans * pow(i.first, (i.second + i.second % 2) / 2);
        //cout << i.first << ':' << i.second << endl;;
    }
    cout << ans;
}