#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
using u128 = __uint128_t;
using ull = unsigned long long;

static inline ull absdiff_i128(i128 x, i128 y){
    i128 z = x - y;
    if (z < 0) z = -z;
    return (ull)z;
}

struct PairHash {
    size_t operator()(const pair<ull,ull> &p) const noexcept {

    auto splitmix = [](uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
    };
    return (size_t)(splitmix(p.first) ^ (splitmix(p.second) >> 1));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull a_in, b_in, K;
    if (!(cin >> a_in >> b_in >> K)) return 0;
    i128 A = (i128)a_in;
    i128 B = (i128)b_in;

    unsigned long long idx = 1;

    if (K == 1ULL) { cout << a_in << '\n'; return 0; }
    if (K == 2ULL) { cout << b_in << '\n'; return 0; }

    unordered_map<pair<ull,ull>, unsigned long long, PairHash> seen;
    seen.reserve(1024);

    while (idx <= K){

        if (idx == K) { cout << (ull)A << '\n'; return 0; }
        if (idx + 1 == K) { cout << (ull)B << '\n'; return 0; }

        if (idx + 2 <= K){

            if (B != 0 && A >= (i128)2 * B){

                i128 numerator = A - B;
                i128 denom = (i128)2 * B;
                i128 t = numerator / denom;
                if (t <= 0) t = 1;

                unsigned long long maxc = (unsigned long long)((K - idx - 1) / 3); 
                if (maxc == 0) {

                    ;
                } else {

                    unsigned long long chunks;
                    if ((u128)t > (u128)maxc) chunks = maxc;
                    else chunks = (unsigned long long)(t);

                    A = A - (i128)2 * B * (i128)chunks;
                    idx += 3ULL * chunks;
                    continue;
                }
            } else if (A != 0 && B >= (i128)2 * A){
                i128 numerator = B - A;
                i128 denom = (i128)2 * A;
                i128 t = numerator / denom;
                if (t <= 0) t = 1;
                unsigned long long maxc = (unsigned long long)((K - idx - 1) / 3);
                if (maxc != 0) {
                    unsigned long long chunks;
                    if ((u128)t > (u128)maxc) chunks = maxc;
                    else chunks = (unsigned long long)(t);
                    B = B - (i128)2 * A * (i128)chunks;
                    idx += 3ULL * chunks;
                    continue;
                }
            }
        }

        ull Au = (ull)A;
        ull Bu = (ull)B;
        pair<ull,ull> key = {Au, Bu};
        auto it = seen.find(key);
        if (it != seen.end()){

            unsigned long long prev_idx = it->second; 
            unsigned long long cycle_len = idx - prev_idx; 
            if (cycle_len == 0) {

                ;
            } else {

                unsigned long long remaining = (K > idx) ? (K - idx) : 0;

                unsigned long long skip = remaining / cycle_len;
                if (skip > 0){
                    idx += skip * cycle_len;

                    continue;
                }
            }
        } else {

            seen.emplace(key, idx);
        }

        ull next = absdiff_i128(A, B);

        A = B;
        B = (i128)next;
        idx += 1ULL;

        if (idx == K) { cout << (ull)A << '\n'; return 0; }
        if (idx + 1 == K) { cout << (ull)B << '\n'; return 0; }
    }

    while (idx < K){
        ull next = absdiff_i128(A, B);
        A = B;
        B = (i128)next;
        idx++;
    }

    cout << (ull)A << '\n';
    return 0;

}