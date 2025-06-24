#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <immintrin.h> 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#define POPCOUNT __builtin_popcount

#if defined(_MSC_VER)
#define ALIGNAS(x) __declspec(align(x))
#else
#define ALIGNAS(x) __attribute__((aligned(x)))
#endif

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> masks_original(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m = 0;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                m |= 1 << (c - 'a');
            }
        }
        masks_original[i] = m;
    }

    const int full = (1 << 26) - 1;
    long long total_count = 0;
    const long long num_total_masks_to_check = 1LL << n;

    const int VEC_SIZE = 8;
    __m256i v_full = _mm256_set1_epi32(full);
    __m256i v_zero = _mm256_setzero_si256();

    for (long long current_block_start_mask = 1; current_block_start_mask < num_total_masks_to_check; current_block_start_mask += VEC_SIZE) {

        ALIGNAS(32) int current_subset_indices_vals[VEC_SIZE];
        int actual_elements_in_this_block = 0; 

        for (int k = 0; k < VEC_SIZE; ++k) {
            long long m_val = current_block_start_mask + k;
            if (m_val < num_total_masks_to_check) {
                current_subset_indices_vals[k] = (int)m_val;
                actual_elements_in_this_block++;
            } else {
                current_subset_indices_vals[k] = 0; 
            }
        }

        if (actual_elements_in_this_block == 0) continue; 

        __m256i v_current_subset_indices = _mm256_loadu_si256((const __m256i*)current_subset_indices_vals);
        __m256i v_combined = _mm256_setzero_si256();

        for (int i = 0; i < n; ++i) {
            __m256i v_bit_to_check = _mm256_set1_epi32(1 << i);
            __m256i v_and_result = _mm256_and_si256(v_current_subset_indices, v_bit_to_check);
            __m256i v_condition_mask = _mm256_cmpgt_epi32(v_and_result, v_zero);
            __m256i v_mask_i = _mm256_set1_epi32(masks_original[i]);
            __m256i masked_val_to_or = _mm256_and_si256(v_mask_i, v_condition_mask);
            v_combined = _mm256_or_si256(v_combined, masked_val_to_or);
        }

        __m256i v_comparison_result = _mm256_cmpeq_epi32(v_combined, v_full);

        int comparison_mask = _mm256_movemask_epi8(v_comparison_result);

        int set_bits_count = POPCOUNT(static_cast<unsigned int>(comparison_mask));

        total_count += set_bits_count / 4;

    }

    cout << total_count << "\n";

    return 0;
}