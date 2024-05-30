#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int factors[(int) 1e7];
void primeFactorization(int n) {
    while (n % 2 == 0) {
        factors[2]++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors[i]++;
            n = n/i;
        }
    }

    if (n > 2)
        factors[n]++;
}
long long pow(long long base, long long exp, int mod = (int) 1e9 + 7) {
    long long ans = 1;
    for(int i = 1; i <= exp; i++) ans = (ans * base) % mod;
    return ans;
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) primeFactorization(i);
    long long ans = 1;
    for(int i = 1; i <= n; i++) ans = (ans * pow(i, factors[i] - factors[i] % 2, 1e9 + 7)) % ((int) 1e9 + 7);
    cout << ans;
}