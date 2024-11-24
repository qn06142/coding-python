#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,fast-math,trapv")
#pragma GCC target("arch=skylake")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
#define int __int128_t
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 5;
#include <cmath>
vector<int> spf(MAXN, 0); 

void sieve() {
    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
}

gp_hash_table<int, int> factorize(int num) {
    assert(num <= 1e7);
    gp_hash_table<int, int> factors;
    while (num > 1) {
        int prime = spf[num];
        factors[prime]++;
        num /= prime;
    }
    return factors;
}

int calc(int N, int K) {
    gp_hash_table<int, int> n = factorize(N);
    gp_hash_table<int, int> k = factorize(K);
    gp_hash_table<int, int> lcm;
    for(pair<int, int> i : n) {
        lcm[i.first] = max(k[i.first], i.second);
    }
    for(pair<int, int> i : k) {
        lcm[i.first] = max(n[i.first], i.second);
    }
    int ans = 1;
    for(pair<int, int> i : lcm) {
        ans *= powl((__float128) i.first, (__float128) i.second - k[i.first] + i.second % 2);
    }
    return ans;
}std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    sieve();

    while (T--) {
        int N, K;
        cin >> N >> K;

        int ans = calc(N, K);
        cout << (__int128) ans << '\n';
    }

    return 0;
}