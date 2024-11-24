#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("arch=alderlake")
const int MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int int_sqrt32(unsigned int x)
{
    int res=0;
    int add= 0x8000;   
    int i;
    for(i=0;i<16;i++)
    {
        int temp=res | add;
        unsigned int g2=temp*temp;      
        if (x>=g2)
        {
            res=temp;           
        }
        add>>=1;
    }
    return res;
}

const int MAX_N = 1e7 + 5; 
vector<int> prime; 
unordered_set<int> primesquare; 
bool is_prime[MAX_N + 5];
void sieve(int n = 1e7 + 2) {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            prime.push_back(p);
            primesquare.insert(p * p); 
        }
    }
}

int countdiv(int n) {
    if (n == 1) return 1; 

    int ans = 1; 

    for (int p : prime) {
        if (p * p * p > n) break; 

        int cnt = 1; 
        while (n % p == 0) { 
            n /= p; 
            cnt++; 
        }

        ans *= cnt; 
    }

    if (is_prime[n]) {
        ans *= 2; 
    } else if (primesquare.find(n) != primesquare.end()) {
        ans *= 3; 
    } else if (n != 1) {
        ans *= 4; 
    }

    return ans; 
}
signed main() {
    int l, r;
    cin >> l >> r;
    sieve(r);
    int ans = 0;
    for (int i = l; i <= r; i++) {
        int divcount = countdiv(i);
        if (divcount & 1) {
            ans += binpow(i, (divcount - 1) >> 1) * int_sqrt32(i) % MOD;
        } else {
            ans += binpow(i, divcount >> 1);
        }
        ans %= MOD;
    }
    cout << ans;
}