
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,sse")
#include <immintrin.h> 
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (m > sum) {
        cout << "NO\n";
        return 0;
    }
    if (m < 0) {
        cout << "NO\n";
        return 0;
    }

    const int W = (m / 64) + 1;
    vector<uint64_t> dp(W, 0);
    dp[0] = 1ULL; 

    vector<int> trace(m + 1, -1);

    vector<uint64_t> shifted(W);
    vector<uint64_t> newbits(W);

    auto maktrace = [&](int ind) {
        for (int wi = 0; wi < W; ++wi) {
            uint64_t word = newbits[wi];
            while (word) {
                uint64_t lowbit = word & -word;
                int b = __builtin_ctzll(word);
                int sum_index = (wi << 6) + b; 
                if (sum_index <= m) trace[sum_index] = ind;
                word ^= lowbit;
            }
        }
    };

    const int stride = 4; 

    for (int i = 1; i <= n; ++i) {
        int shift = a[i];
        if (shift == 0) {

            continue;
        }

        fill(shifted.begin(), shifted.end(), 0ULL);
        fill(newbits.begin(), newbits.end(), 0ULL);

        int word_shift = shift >> 6;         
        int bit_shift = shift & 63;          

        if (bit_shift == 0) {

            for (int src = 0; src < W; ++src) {
                int tgt = src + word_shift;
                if (tgt >= W) break;
                shifted[tgt] = dp[src];
            }
        } else {

            for (int src = 0; src < W; ++src) {
                uint64_t v = dp[src];
                if (!v) continue;
                int tgt = src + word_shift;
                if (tgt < W) {
                    shifted[tgt] |= (v << bit_shift);
                }
                if (tgt + 1 < W) {
                    shifted[tgt + 1] |= (v >> (64 - bit_shift));
                }
            }
        }

        int k = 0;
        for (; k + stride - 1 < W; k += stride) {
            __m256i s = _mm256_loadu_si256((const __m256i*)(shifted.data() + k));
            __m256i d = _mm256_loadu_si256((const __m256i*)(dp.data() + k));
            __m256i notd = _mm256_xor_si256(d, _mm256_set1_epi64x(-1LL)); 
            __m256i nb = _mm256_and_si256(s, notd);
            _mm256_storeu_si256((__m256i*)(newbits.data() + k), nb);
        }

        for (; k < W; ++k) {
            newbits[k] = shifted[k] & ~dp[k];
        }

        bool any_new = false;
        for (int k = 0; k < W; ++k) if (newbits[k]) { any_new = true; break; }
        if (any_new) {
            maktrace(i);
        }

        int k2 = 0;
        for (; k2 + stride - 1 < W; k2 += stride) {
            __m256i s = _mm256_loadu_si256((const __m256i*)(shifted.data() + k2));
            __m256i d = _mm256_loadu_si256((const __m256i*)(dp.data() + k2));
            __m256i res = _mm256_or_si256(d, s);
            _mm256_storeu_si256((__m256i*)(dp.data() + k2), res);
        }
        for (; k2 < W; ++k2) dp[k2] |= shifted[k2];

        if ( (dp[m >> 6] >> (m & 63)) & 1ULL ) break;
    }

    if (((dp[m >> 6] >> (m & 63)) & 1ULL) == 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> res;
    int cur = m;
    while (cur > 0) {
        int idx = trace[cur];
        res.push_back(idx);
        cur -= a[idx];
    }
    for (int i = (int)res.size() - 1; i >= 0; --i) {
        cout << res[i] << (i ? ' ' : '\n');
    }
}