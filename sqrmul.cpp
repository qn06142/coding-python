#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD = 1e9 + 7;
const long long MAXN = 5e7 + 5;
long long divs[MAXN];

// Hàm tính lũy thừa với mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Hàm phân tích thừa số nguyên tố
void factorize(long long m) {
    for (long long i = 2; i * i <= m; i++) { 
        long long cnt = 0;
        while (m % i == 0) { 
            cnt++;
            m /= i; 
        } 
        if (cnt > 0) {
            divs[i] = max(cnt, divs[i]);
        }
    } 
    if (m > 1) {
        divs[m] = max(divs[m], 1LL);
    }
}

int main() { 
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        factorize(A[i]);
    }

    long long ans = 1;
    for (long long i = 2; i < MAXN; i++) {
        if (divs[i] > 0) {
            long long exponent = (divs[i] + 1) / 2 * 2; // Làm cho exponent thành số chẵn
            ans = (ans * mod_pow(i, exponent, MOD)) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
